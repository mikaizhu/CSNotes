# 说明

记录一些课程中的重点

- [shell 命令搜索网站](https://wangchujiang.com/linux-command/) 
- [linux man page [English]](https://man7.org/linux/man-pages/)
- [linux man page [中文]](https://manpages.debian.org/unstable/manpages-zh/Button.3tk.zh_CN.html) 

# 01概览与shell笔记

- [参考笔记](https://missing-semester-cn.github.io/2020/course-shell/) 
- [习题解答](https://missing-semester-cn.github.io/missing-notes-and-solutions/2020/solutions/course-shell-solution/) 

1. shell是什么？

shell 是用户与电脑内核交互的一个编程环境

2. shell如何执行这些命令？

shell 是如何知道去哪里寻找 date 或 echo 的呢？
其实，类似于 Python 或 Ruby，shell 是一个编程环境，所以它具备变量、条件、循环和函数（下一课进行讲解）。
当你在 `shell` 中执行命令时，您实际上是在执行一段 `shell` 可以解释执行的简短代码。
如果你要求 `shell` 执行某个指令，但是该指令并不是 `shell` 所了解的编程关键字，那么它会去咨询环境变量`$PATH`，它会列出当 `shell` 接到某条指令时，进行程序搜索的路径：

```
missing:~$ echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
missing:~$ which echo
/bin/echo
missing:~$ /bin/echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
```

当我们执行 `echo` 命令时，`shell` 了解到需要执行 `echo` 这个程序，随后它便会在 `$PATH` 中搜索由 : 所分割的一系列目录，基于名字搜索该程序。
当找到该程序时便执行（假定该文件是 可执行程序，后续课程将详细讲解）。确定某个程序名代表的是哪个具体的程序，可以使用 which 程序。
我们也可以绕过 $PATH，通过直接指定需要执行的程序的路径来执行该程序



2. 使用`ls -l` 命令查看的结果是什么意思？

```
missing:~$ ls -l /home
drwxr-xr-x 1 missing  users  4096 Jun 15  2019 missing
```

首先，本行第一个字符 `d`表示 `missing` 是一个目录。
然后接下来的九个字符，每三个字符构成一组。
`（rwx）`. 它们分别代表了文件所有者`（missing）`，用户组`（users）` 以及其他所有人具有的权限。
其中` - `表示该用户不具备相应的权限。从上面的信息来看，只有文件所有者可以修改`（w）`，`missing` 文件夹 （例如，添加或删除文件夹中的文件）。
为了进入某个文件夹，用户需要具备该文件夹以及其父文件夹的“搜索”权限（以“可执行”：`x`）权限表示。
为了列出它的包含的内容，用户必须对该文件夹具备读权限（`r`）。对于文件来说，权限的意义也是类似的。
注意，`/bin` 目录下的程序在最后一组，即表示所有人的用户组中，均包含 `x` 权限，也就是说任何人都可以执行这些程序。

3. shell 中'流'的概念

在 shell 中，程序有两个主要的“流”：它们的输入流和输出流。 
当程序尝试读取信息时，它们会从输入流中进行读取，当程序打印信息时，它们会将信息输出到输出流中。 
通常，一个程序的输入输出流都是您的终端。也就是，您的键盘作为输入，显示器作为输出。 但是，我们也可以重定向这些流, 使用 `>, <, >>, |`,
其中管道操作符允许我们将一个程序的输出和另外一个程序的输入连接起来

**注意操作符不是程序命令，`|`、`>`、和 `<` 是通过 shell 执行的，而不是被各个程序单独执行。** 

4. 一个例子：假如我要修改亮度, 使用下面方式将3写入文件

```
$ sudo find -L /sys/class/backlight -maxdepth 2 -name '*brightness*' # 搜索文件最大深度为2，名字为brightness的
/sys/class/backlight/thinkpad_screen/brightness
$ cd /sys/class/backlight/thinkpad_screen
$ sudo echo 3 > brightness # 将3输出重定向到文件中
An error occurred while redirecting file 'brightness'
open: Permission denied
```

上面例子中，本来想将3重定向到文件中，但是却报错，明明使用了sudo命令

主要原因为：系统会先尝试打开后面的文件，文件的权限是当前用户，所以不能以这样的方式sudo, 修改为下面方式

```
echo 3 | sudo tee brightness # 程序会以sudo的权限先打开文件，然后以管道操作符以3为输出流作为这个程序的输入流
```

# 02 shell命令的使用

1. 什么是shell进程替换？

参考：
- http://c.biancheng.net/view/3025.html
- https://missing-semester-cn.github.io/2020/shell-tools/

与进程替换相对应的是命令替换, 命令替换是把一个命令的输出结果赋值给另一个变量，例如`dir_files=`ls -l``或`date_time=$(date)`.

进程替换有什么作用？

例如:

```
echo "http://c.biancheng.net/shell/" | read
echo $REPLY
```

以上代码输出结果总是为空，因为 echo 命令在父 Shell 中执行，而 read 命令在子 Shell 中执行，当 read 执行结束时，子 Shell 被销毁，REPLY 变量也就消失了。
管道中的命令总是在子 Shell 中执行的，任何给变量赋值的命令都会遭遇到这个问题。进程替换可以保证前后两个命令处于同一个进程中.

> `read`命令是从输入流中读取数据，然后保存在后面的变量中，如果没有提供变量，则默认保存在`$RAPLY`中.

使用进程替换的写法为：

方法1:
```
read < <(echo "http://c.biancheng.net/shell/")
echo $REPLY
```

方法2:

```
echo "C语言中文网" > >(read; echo "你好，$REPLY")
```

方法1中，`<(script)` 括号包裹起来的为脚本程序，`<()` 将程序的输出保存，并用`<`重定向提供给read命令

方法2中亦是如此

**进程替换本质**:

实际上进程替换会将进程与文件链接起来, 文件如下，`>()`只是一个文件.

```
[c.biancheng.net]$ echo >(true)
/dev/fd/63
[c.biancheng.net]$ echo <(true)
/dev/fd/63
[c.biancheng.net]$ echo >(true) <(true)
/dev/fd/63 /dev/fd/62
```

分析下该命令：

```
echo "shellscript" > >(read; echo "hello, $REPLY")
```

`>()`会创建一个临时文件，`>`将shellscript重定向到该文件中

`>()`中的第一个命令是 read，它需要从标准输入中读取数据，此时就用`/dev/fd/63`作为输入文件，把该文件的内容交给 read 命令，
接着使用 echo 命令输出 read 读取到的内容。

可以看到，`/dev/fd/63`文件起到了数据中转或者数据桥梁的作用，借助重定向，它将`>()`内部的命令和外部的命令联系起来，使得数据能够在这些命令之间流通。

2. 什么是shell的通配？

当想要利用通配符进行匹配时，你可以分别使用`?` 和 `*` 来匹配一个或任意个字符。
例如，对于文件`foo`, `foo1`, `foo2`, `foo10` 和 `bar`, `rm` `foo?`这条命令会删除`foo1` 和 `foo2` ，而`rm foo*` 则会删除除了`bar`之外的所有文件。

花括号`{}`当你有一系列的指令，其中包含一段公共子串时，可以用花括号来自动展开这些命令。这在批量移动或转换文件时非常方便。

```
convert image.{png,jpg}
# 会展开为
convert image.png image.jpg

cp /path/to/project/{foo,bar,baz}.sh /newpath
# 会展开为
cp /path/to/project/foo.sh /path/to/project/bar.sh /path/to/project/baz.sh /newpath

# 也可以结合通配使用
mv *{.py,.sh} folder
# 会移动所有 *.py 和 *.sh 文件

mkdir foo bar

# 下面命令会创建foo/a, foo/b, ... foo/h, bar/a, bar/b, ... bar/h这些文件
touch {foo,bar}/{a..h}
touch foo/x bar/y
# 比较文件夹 foo 和 bar 中包含文件的不同
diff <(ls foo) <(ls bar)
# 输出
# < x
# ---
# > y
```

# 03 data wrangling(数据处理)

本实验利用journalctl来获取要处理的数据，从中整理出有价值的信息，以及学习相关工具的使用

1. 什么是journalctl, 如何好好利用

journalctl 是系统查看日志的一个程序，在Linux服务器上输入这个命令可以查看系统日志，包括有谁登陆了我们的系统

常用命令：

```
journalctl -n 20 # 使用-n参数可以显示最后n行日志，如果不指定行数，默认显示10行。
journalctl --since=-30m # 显示最近30分钟的日志。
journalctl --since="2021-01-01" # 显示2021年以来的日志。
journalctl --since=today # 显示今天的日志。
```

还可以通过journalctl查看ssh登陆的信息

```
ssh root@182.xxx.xxx 'journalctl -n 20' | grep ssh > ssh.log
```

这样就会将结果保存到本地的`ssh.log` 文件中

2. `sed` 命令的使用方式
- TODO

3. `awk` 命令的使用方式
- TODO

4. `grep` 命令的使用方式
- TODO

3. 正则表达式

- [正则表达式练习](https://regexone.com/) 

# 04 commandline environment

1. 当我们使用`control+c` 终止命令的时候，其原理是什么？

其使用的是UNIX的信号原理，使用`man signal` 可以查看这些信号，使用control+c后，shell会向该进程发送sigint(signal interupt)信号，程序捕捉到后会终止

我们可以使用代码让程序忽略SIGINT信号, 这样control+c就不能中断该程序

`control+z`命令会终止该程序, suspend. 

我们可以使用 `fg` 或 `bg` 命令恢复暂停的工作。它们分别表示在前台继续或在后台继续。

`jobs` 命令会列出当前终端会话中尚未完成的全部任务。(注意是当前终端下)

当我们关闭终端，该终端会向程序发出SIGHUP信号，程序接收后就会断开程序, 因此使用`nohup` 命令让该进程忽略 SIGHUP信号, 在末尾加`&` 表示让该程序后台运行
因此两者结合表示让该代码在后台运行，并忽略SIGHAP信号

我们还可以使用`kill -<> PID` 来向进程发送信号, 同时每个信号都有对应的index，如`kill -9 pid` 

```
$ sleep 1000
^Z
[1]  + 18653 suspended  sleep 1000

$ nohup sleep 2000 &
[2] 18745
appending output to nohup.out

$ jobs
[1]  + suspended  sleep 1000
[2]  - running    nohup sleep 2000

$ bg %1
[1]  - 18653 continued  sleep 1000

$ jobs
[1]  - running    sleep 1000
[2]  + running    nohup sleep 2000

$ kill -STOP %1
[1]  + 18653 suspended (signal)  sleep 1000

$ jobs
[1]  + suspended (signal)  sleep 1000
[2]  - running    nohup sleep 2000

$ kill -SIGHUP %1
[1]  + 18653 hangup     sleep 1000

$ jobs
[2]  + running    nohup sleep 2000

$ kill -SIGHUP %2
```

2. tmux的使用

tmux 可以使用`tmux a` 来表示`tmux attach` 的缩写

3. 什么是配置文件(dotfiles)

很多程序的配置都是通过dotfiles来设置的（之所以称为点文件，是因为它们的文件名以 . 开头，例如 ~/.vimrc。也正因为此，它们默认是隐藏文件，ls并不会显示它们）。

shell 的配置也是通过这类文件完成的。在启动时，您的 shell 程序会读取很多文件以加载其配置项。根据 shell 本身的不同，您从登录开始还是以交互的方式完成这一过程可能会有很大的不同。关于这一话题，这里 有非常好的资源

对于 bash来说，在大多数系统下，您可以通过编辑 .bashrc 或 .bash_profile 来进行配置。在文件中您可以添加需要在启动时执行的命令，例如上文我们讲到过的别名，或者是您的环境变量。

如何利用工具管理dotfiles？参考：https://dotfiles.github.io/utilities/

4. 如何使用ssh免密码登陆

本地生成密钥，使用 `ssh-keygen` 命令可以生成一对密钥, 我们将公钥给服务器，私钥自己保留，登陆的时候服务器会验证私钥，从而不需要密码.

我们除了可以将文件传给服务器，还可以使用`ssh-copy-id` 将公钥传到服务器中

```
cat .ssh/id_ed25519.pub | ssh foobar@remote 'cat >> ~/.ssh/authorized_keys'
```

或者使用上面命令传

5. 如何通过ssh复制文件到服务器上

当有大量文件或者文件很大时，使用rsync命令更好，如果突然中断，可以从中断续传，并且可以检测哪些文件重复了

ssh+tee, 最简单的方法是执行 ssh 命令，然后通过这样的方法利用标准输入实现 cat localfile | ssh remote_server tee serverfile。回忆一下，tee 命令会将标准输出写入到一个文件；

scp ：当需要拷贝大量的文件或目录时，使用scp 命令则更加方便，因为它可以方便的遍历相关路径。语法如下：scp path/to/local_file remote_host:path/to/remote_file；

rsync 对 scp 进行了改进，它可以检测本地和远端的文件以防止重复拷贝。它还可以提供一些诸如符号连接、权限管理等精心打磨的功能。甚至还可以基于 --partial标记实现断点续传。rsync 的语法和scp类似；

6. 如何配置ssh文件

- 可以通过alias
- 通过~/.ssh/config

如：

```
Host vm
    User foobar
    HostName 172.16.174.141
    Port 2222
    IdentityFile ~/.ssh/id_ed25519
    LocalForward 9999 localhost:8888
```

7. 什么是端口转发, 和端口映射有什么区别？

端口转发是通过ssh来进行的信息传输，有数据加密，而端口映射没有

端口转发和端口映射差不多，都是将内网服务器的某个端口，与公网服务器的某个端口链接起来，这样如果直接访问公网的这个端口，就可以与内网进行通信


8. link文件有什么用？(ln -s)

当我们点击link文件后，link 知道源文件在哪


