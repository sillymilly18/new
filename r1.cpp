#include <string_view>

#include <cassert>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include <cctype>

enum class IT_Priority
{
    Critical = 0,
    High = 1,
    Medium = 2,
    Low = 3
};

template <typename Priority>
struct Task
{
    std::string tag;
    std::string title;
    std::string description;
    int duration;
    Priority priority;
    std::chrono::system_clock::time_point deadline;
};

template <typename Priority>
class TaskScheduler
{
public:
    static inline constexpr int DAILY_CAPACITY_HOURS = 10;

    TaskScheduler() = default;

    // RULE OF FIVE
    ~TaskScheduler() = default;

    TaskScheduler(const TaskScheduler &) = delete;
    TaskScheduler &operator=(const TaskScheduler &) = delete;

    TaskScheduler(TaskScheduler &&) = default;
    TaskScheduler &operator=(TaskScheduler &&) = default;

    TaskScheduler &add_task(const string &tag,
                            const string &title, const string &description,
                            int duration, Priority priority, std::chrono::system_clock::time_point deadline)
    {
        Task<Priority> task{
            tag, title, description, duration, priority, deadline};
        if (validate_task(task))
        {
            tasks_.push_back(task);
        }
        return *this;
    }

private:
    std::vector<Task<Priority>> tasks_;
    std::vector<Task<Priority>> scheduled_;
    std::vector<Task<Priority>> dropped_;

    // календарь = несколько дней,
    // внутри каждого дня несколько Task
    std::vector<std::vector<Task<Priority>>> calendar_;

    bool validate_task(const Task<Priority> &task) const
    {
        if (task.tag.size() > 20)
        {
            return false;
        }
        if (task.duration <= 0)
        {
            return false;
        }
        for (char c : task.tag)
        {
            if (!isgraph(static_cast<unsigned char>(c)))
            {
                return false;
            }
        }
        return true;
    }
};

// evwe

// 3434