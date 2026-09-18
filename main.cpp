using namespace std::chrono;

int main
{
    hours d1 = hours(24);
    hours d2 = hours(48);
    hours d3 = hours(72);
    hours d5 = hours(120);
    hours d7 = hours(168);

    hours now =
        sys_days{2026y / May / 27d} + 12h + 0min + 0s;

    TaskScheduler<IT_Priority> scheduler(4, now);

    scheduler
        .add_task(...)
        .add_task(...)
        .add_task(...)...
        .optimize();

    std::cout << "=== OPTIMIZED CALENDAR ===\n";
    ... std::cout << scheduler.export_calendar();
}