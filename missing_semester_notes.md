# 说明

记录一些课程中的重点

- [shell 命令搜索网站](https://wangchujiang.com/linux-command/) 

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

