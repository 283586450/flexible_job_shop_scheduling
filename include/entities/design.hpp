// 这里描述了problem data的设计

/*
要定义一个problem， 需要 数据 + constraint + objective
比如一个step，它包含step的基本信息，比如id，avbel_machine等。
它还应该包含相应的逻辑信息，比如constraint和objective。
要定义一个constraint： step
data里面应该包含一个函数指针的列表，这个列表中的每一个函数指针都是一个constraint。

 */

class ProblemData
{
private:
    int stepID1;   // 这是一个成员变量

public:
    std::function<bool(const Solution&)> createConstraint(int stepID2)
    {
        return [this, stepID2](const Solution& solution) {
            // 获取 start_time1 和 start_time2
            int start_time1 = solution.getStartTime(stepID1);
            int start_time2 = solution.getStartTime(stepID2);

            // 检查 start_time1 是否小于 start_time2
            return start_time1 < start_time2;
        };
    }
};

/*
但是这里面有this指针，复制出来后，可不可以单独调用，还是必须用ProblemData的对象调用
GitHub Copilot
当你复制一个包含 this 指针的 std::function 对象时，复制出来的 std::function
对象会捕获和存储原对象的 this 指针。这意味着，复制出来的 std::function
对象可以独立于原 ProblemData 对象被调用。

在你的代码中，this 指针被用来访问 ProblemData 的成员变量 stepID1。当你复制
std::function 对象时，它会复制 this 指针，因此复制出来的 std::function
对象仍然可以访问原 ProblemData 对象的 stepID1 成员变量。

这意味着，即使原 ProblemData 对象被销毁，复制出来的 std::function
对象仍然可以被调用。但是，你需要注意的是，如果原 ProblemData 对象被销毁，那么
std::function 对象中的 this
指针就会变成悬挂指针，这可能会导致未定义的行为。因此，你需要确保 std::function
对象的生命周期不会超过它所引用的 ProblemData 对象的生命周期。
 */