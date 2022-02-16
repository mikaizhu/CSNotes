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
