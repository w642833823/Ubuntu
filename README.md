# 提交代码步骤
从Git上下载项目
git clone https://github.com/你的目标项目.git
把你的要上传代码项目移动到下载的项目中去
3 跟踪项目
git status
4建立跟踪
git add 你复制来的项目名
git add My_QQ
5 git status
git branch
6 git add *
git commit 
填写变更信息
8 提交项目
git push

#设置git push github 免密输入账号密码的方法

git config --global credential.helper store

打开~/.gitconfig文件，会发现多了一项

［credential］
          helper=store
此时，再次输入用户名和密码，以后再次push即可免去输入用户名和密码


上传代码的步骤方法二（需要特定条件）

1 echo "# My_QQ">>README.md
2  git init 
   git add README.md
   git commit -m "push README"
   git remote add origin https://github.com/项目地址.git            
   git push -u origin master  
           
3  git status 
//添加跟踪文件
4  git add my_widget 
5  git status
6
7 git commit -m "push my_widget"  
  
       
5 git push 