# AutoGrader 自动阅卷系统

AutoGrader 是一款基于 C 语言编写的简易阅卷工具，支持通过文件或手动输入的方式导入标准答案和学生答案，完成阅卷对比、结果计算和给出正确率。

---

## 本地编译

需要 CMake + GCC (MinGW) 环境，本项目在 CLion 中编写：

```bash
mkdir build
cd build
cmake ..
make
```

或者直接在 CLion 中 Run main.c 即可运行

如果不用CLion，使用其他可编写C语言编译器，可忽略CMake文件，楼主没有更改CMake文件。

---

## 功能介绍

| 步骤 | 说明 |
|--------|--------|
| 1. 导入标准答案 | 支持文件格式 "1 A\n2 B" 或手动输入 |
| 2. 导入学生答案 | 样式同上，存入数组 |
| 3. 自动阅卷 | 对比题号和答案，统计正确数/总题/正确率 |

---

## 格式要求

### 标准答案文件格式

```txt
1 A
2 B
3 C
4 D
```

### 学生答案文件
```txt
1 A
2 C
3 C
4 D
```

---

## 代码模块

| 函数 | 说明 |
|--------|------|
| `display()` | 系统欢迎界面显示 |
| `importAnswer()` | 导入标准答案数组 |
| `importStuAnswer()` | 导入学生答案数组 |
| `autoGrade()` | 根据题号对比答案，计算结果 |

---

## 方法调用流程

```c
// 1. 导入标准答案
standard_count = importAnswer(answer);

// 2. 导入学生答案
student_count = importStuAnswer(stuAnswer);

// 3. 自动阅卷操作
autoGrade(answer, standard_count, stuAnswer, student_count);
```

---

## 常见问题 FAQ

| 问题 | 原因 |
|-------|------|
| 正确率为 0.00% | 导入格式错误/数组传递顺序错误 |
| 文件打不开 | 名称包含 \n/格式错误 |
| 数组冒泡 | 导入时 count++ 超过 MAX_QUESTIONS |

---

## 本地 Git 控制

规范分支：`dev` 为开发分支，最终合并至 `master`

```bash
git checkout -b dev
git add .
git commit -m "feat: 完成阅卷操作"
git push origin dev

# merge dev -> master
```

---

## 其他功能等待扩展
- [ ] 错题列表
- [ ] 学生结果导出 TXT
- [ ] GUI 图形界面

---

如需进一步合作或进行实操讲解，欢迎接入 GitHub / Gitee 进行 Fork + Pull Request 合作！


