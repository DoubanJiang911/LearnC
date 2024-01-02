char* dayOfTheWeek(int day, int month, int year) {
    time_t rawtime;
    struct tm* timeinfo;
    //int year, month, day;
    //const char* weekday[] = { "周日", "周一","周二", "周三","周四", "周五", "周六" };
    const char* weekday[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

    /* 用户输入日期 /
    printf("年: "); fflush(stdout); scanf("%d", &year);
    printf("月: "); fflush(stdout); scanf("%d", &month);
    printf("日: "); fflush(stdout); scanf("%d", &day);*/

    /* 获取当前时间信息，并修改用户输入的输入信息 */
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    timeinfo->tm_year = year - 1900;
    timeinfo->tm_mon = month - 1;
    timeinfo->tm_mday = day;

    /* 调用 mktime: timeinfo->tm_wday  */
    mktime(timeinfo);

    //printf("那一天是：%s\n", weekday[timeinfo->tm_wday]);
    return weekday[timeinfo->tm_wday];
}
