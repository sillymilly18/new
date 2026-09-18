#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum IT_Priority
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
    time_point deadline;
};

static inline constexpr int DAILY_CAPACITY_HOURS = 10;
static inline constexpr int TASK_TAG_LEN = 16;
static inline constexpr int TASK_DURATION_LEN = 4;

template <typename Priority>
class TaskScheduler
{
public:
    using sys_days = std::chrono::sys_time<std::chrono::days>;

    explicit TaskScheduler() {}

    Priority add_task() {}

    TaskScheduler<Priority> &
    find_task(const std::string &tag) {}

    Priority optimize() {}

    Priority scheduled_tasks() const {}

    Priority dropped_tasks() const {}

    Priority export_calendar() const {}

private:
    vector<Task<Priority>> tasks_;
    vector<int> scheduled_;
    vector<int> dropped_;
    std::vector<vector<int>> calendar_;
    vector<int> horizon_days_;

    std::chrono::system_clock::time_point planning_start_;

    void invalidate_cache() {}

    void validate_task(
        const TaskScheduler<Priority> &t) const {}
};