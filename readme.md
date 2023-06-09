# 第五次上机作业

## 设计内容

模拟一个简单的邮件后台管理系统，该系统具有增加账号、修改账号、删除账号、查询账号的功能，同时也能够对邮件进行CRUD操作

## 难点

- 在mfc中连接数据库
- sql语句
- 对业务操作进行设计

## ER图

![E-R图](https://github.com/Yikuni/MFC-Dao-example/blob/master/E-R%E5%9B%BE.jpg)

## 设计思路

由于系统比较简单，故仅分2层：持久层和视图层，持久层负责直接面对数据库进行CRUD，视图层负责提供用户操作接口

另外由于框架等原因，暂时不做sql注入检查

不考虑高并发状况

### 表的设计

#### 邮箱表

| 字段      | 类型        | 约束                |
| --------- | ----------- | ------------------- |
| ID        | int         | auto increment 主键 |
| mail_name | varchar(32) | unique not null     |
| password  | varchar(64) | not null            |

#### 邮件表

| 字段    | 类型          | 约束                |
| ------- | ------------- | ------------------- |
| ID      | int           | auto increment 主键 |
| mail_id | int           | not null            |
| title   | varchar(64)   | not null            |
| content | varchar(4096) | not null            |
| from    | varchar(128)  | not null            |

### 连接数据库

由于是一个小型的系统，故只使用一个连接来对接数据库

使用单例模式，用DBManager类的Instance维持对数据库的连接

### 数据库操作

对2张表分别有CRUD操作，直接用静态方法进行操作

## 实现的功能

### UI

![image-20230523211231754](https://github.com/Yikuni/MFC-Dao-example/blob/master/image-20230523211231754.png)

### 关于邮箱

- 查找所有已注册邮箱

  > 左键点击显示，会显示所有已注册的邮箱

- 修改用户名和密码

  > 双击要修改的邮箱:
  > ![image-20230523211455733](https://github.com/Yikuni/MFC-Dao-example/blob/master/image-20230523211455733.png)
  >
  > 在输入栏中修改信息后点击修改,页面数据将自动刷新

- 创建用户

  > 在输入框中输入账号和密码创建账号, 如果账号名重复则提示创建失败

- 删除用户

  > 选中用户后点击删除进行删除操作

### 关于邮件

- 显示账号所有的邮件

  > 选中账号后自动查询该账号拥有的邮件, 如果没有则显示空

- 删除邮件

  > 双击选中邮件后点击删除邮件按钮进行删除

- 添加邮件

  > 在右侧输入框中输入邮件信息后点击按钮进行添加

- 查看邮件

  > 双击邮件, 右侧会显示相关信息
