版本控制
git init
这个操作是初始化一个版本仓库

git clone https://github.com/gdh6542.git
克隆远端仓库到本地

git pull
从远程仓库把代码取下来，将其他人的代码提交的代码同步到本地。

git status
查看当前分支状态。

git add
把文件的改动增加到我们的新版本的缓存中（还没提交新版本）。

git commit
提交/增加一个新版本。

git push
将本地代码推送到远程仓库。

git checkout
切换分支

git branch
查看当前分支,git branch xx创建新的分支

git remote
查看当前的远程端

git merge
git merge develop合并分支到当前分支

git reset
git reset HEAD 以取消之前 git add 添加了但不希望包含在下一提交快照中的缓存

git rm
git rm file将文件从缓存区移除，同时硬盘里的对应文件也会删除。

说明
每次写代码前，先同步一下，你可以在Git Bash中输入：

git pull [远程仓库名] [分支名] #后面两个不写默认是origin master
也可以QtCreator的菜单-工具-Git-Remote Repository-Pull。

然后开始写，如果需要，你可以执行 git branch (branchname) 来创建分支， 使用 git checkout (branchname) 命令切换到该分支。

写完后要提交代码。工具-Git-Local Repository- commit...，然后输入一下这次提交的介绍。也可以在Git Bash 中输入

git add . # .代表当前目录下所有文件
git commit -m "提交说明"
接下来我们的代码需要同步给remote。工具-Git-Remote Repository-Push。或者命令行：

git push
git push -u origin master # 如果是第一次提交
git push origin develop #如果是提交分支