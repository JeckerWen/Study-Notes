# Chapter05 

### 5.5.2 基础命令操作 pages.118
 
- 简单的计算器:`bc`

- `man`: `/usr/share/man/`

		NAME:该命令的全名及用途简介;
		SYNOPSIS:该命令的基本语法;
			OPTIONS:针对SYNOPSIS部分中，有列举的所有可用的选项说明;
		DESCRIPTION:详细说明刚才语法可以用的的参数;
		ENVIRONMENT:与这个命令相关环境参数的说明;
		COMMANDS:当这个程序在执行时，可以在此程序中执行的命令;
		FILES:这个程序或数据所使用的或参考或连接到的某些文件;
		SELL ALSO:这些命令或数据有相关的其他说了;
		EXAMPLE:一些可以参考的范例;
		BUGS:是否有相关的错误.

	- man page 常见数字的意义(`page124`, `表5-1`)

	- `makewhatis`:创建whatis数据库(root运行)

	- `whatis`:可以某个命令的man page信息

- `info`: `/usr/share/info`

	- info page各文件说明相关性示意图(`page129`. `图5-23`)
	
			File：代表这个page页面的提供源
			Node：这个页面属于的节点
			Next:下一个节点的名称
			Up:上一个节点的总揽页面
			prev:前一个节点

- 查看某个软件的服务说明文档: `/usr/share/doc/`
		