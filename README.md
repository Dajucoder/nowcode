# NowCode 算法训练

这是一个用于训练牛客网算法比赛题目的C++项目。该项目提供了一个完整的环境配置和代码模板，帮助你更高效地练习算法题目并参与牛客网的算法竞赛。

## 项目特点

- 预配置的C++开发环境
- 常用算法和数据结构的工具库
- 标准的代码模板，快速开始编写解题代码
- 简单的编译和运行命令

## 环境要求

- C++编译器 (推荐 g++ 7.0 或更高版本)
- Make 工具
- Git

## 项目结构

```
.
├── .gitignore          # Git忽略文件配置
├── Makefile            # 编译和运行配置
├── README.md           # 项目说明文档
├── src/                # 源代码目录
│   ├── template.cpp    # 代码模板
│   └── utils/          # 工具库
│       └── algorithm_utils.h  # 算法工具库
├── bin/                # 编译后的可执行文件目录
└── build/              # 构建临时文件目录
```

## 使用方法

### 1. 克隆项目

```bash
git clone https://github.com/你的用户名/nowcode.git
cd nowcode
```

### 2. 创建新的解题文件

在`src`目录下创建你的解题文件，例如`src/problem_1001.cpp`。你可以复制`template.cpp`作为起点：

```bash
cp src/template.cpp src/problem_1001.cpp
```

### 3. 编写代码

编辑你的解题文件，实现算法。如果需要使用算法工具库，可以包含相应的头文件：

```cpp
#include "utils/algorithm_utils.h"
```

### 4. 编译和运行

使用Makefile编译和运行你的代码：

```bash
# 编译
make compile FILE=src/problem_1001.cpp

# 编译并运行
make run FILE=src/problem_1001.cpp
```

## 常用算法工具

项目中的`algorithm_utils.h`提供了多种常用算法实现：

- 快速幂算法
- 最大公约数(GCD)和最小公倍数(LCM)
- 素数判断和埃氏筛法
- 二分查找
- 并查集

## 贡献指南

欢迎提交Pull Request来改进这个项目。你可以：

- 添加新的算法工具
- 改进现有代码
- 修复bug
- 添加更多有用的功能

## 许可证

[MIT License](LICENSE)

## 致谢

感谢牛客网提供的优质算法竞赛平台。

---

祝你在算法竞赛中取得好成绩！
