#include <stdio.h>
#include <string.h>

int countWords(char** words1, int words1Size, char** words2, int words2Size) {
    int cnt = 0;
    for (int i = 0; i < words1Size; i++) {
        // temp记录words1当前遍历下标的字符串，flag判断当前字符串在words1数组内是否重复
        char temp[31];
        strcpy(temp, words1[i]);
        bool flag = true;
        for (int j = 0; j < words1Size; j++) {
            if (i == j) {
                continue;  // 跳过相同下标
            }
            else if (strcmp(temp, words1[j]) == 0) {
                flag = false;
                break;
            }
        }
        // 如果temp不属于words1中重复的字符串，则统计其在words2中出现的次数t，出现2次则终止遍历words2，倘若仅出现1次则符合需求cnt+1
        if (flag == true) {
            int t = 0;
            for (int k = 0; k < words2Size; k++) {
                if (strcmp(temp, words2[k]) == 0) {
                    t++;
                    if (t > 1) {
                        break;
                    }
                }
            }
            if (t == 1) {
                cnt++;
            }
        }
    }
    return cnt;
}
