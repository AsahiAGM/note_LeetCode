/*
    最適化できる場所はたくさんある気もするが、take1で RT:beat 100%
    ただし、memory:beat 44%。まだ200kbほど節約できる余地がある
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../util.h"

typedef struct s_recc_stat{
    char    **result;
    char    *comb;
    int     res_idx;
}   t_recc_stat;

typedef struct s_nummap{
    char    **map;
    int     *sizes;
}   t_nummap;

int digitsLenCount(char *digs)
{
    int _count = 0;
    while (*digs) 
    {
        _count++;
        digs++;
    }
    return (_count);
}

int convertNum(char *digits, int index)
{
    return (digits[index] - '0');// digits[i] is a digit in the range ['2', '9'].
}

char *__strdup(char *src, int size)
{
    char *buf = (char *)malloc(sizeof(char) * size + 1);
    char *head = buf;

    for(int i=0; i<size ;i++)
    {
        *buf = *src;
        buf++;
        src++;
    }
    *buf = '\0';

    return (head);
}

void generateComb(char *digits, int digitSize, int dig_idx, t_recc_stat *stat, t_nummap *map)
{
    if (dig_idx == digitSize)
    {
        stat->result[stat->res_idx] = __strdup(stat->comb, digitSize);
        stat->res_idx += 1;
        return;
    }
    
    int num = convertNum(digits, dig_idx);

    for (int i = 0; i < map->sizes[num - 2]; ++i) {
        stat->comb[dig_idx] = map->map[num - 2][i];
        generateComb(digits, digitSize, dig_idx + 1, stat, map);
    }

    return;
}

char** letterCombinations(char* digits, int* returnSize) {
    t_recc_stat stat;
    t_nummap    nummap;
    int         combCount = 0;
    int         digitsLen = digitsLenCount(digits);

    if (!digits[0])
        return (NULL);

    // init
    char *__map[9] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz",""};
    int  __sizes[9] = {3,3,3,3,3,4,3,4,1};
    nummap.map = __map;
    nummap.sizes = __sizes;
    
    for(int i=0; i<digitsLen; i++)
    {
        int num = convertNum(digits, i); 
        combCount = (combCount > 0) ? combCount * __sizes[num - 2] : __sizes[num - 2];
    }
    stat.result = (char **)malloc(sizeof(char *) * (combCount+1));
    if (!stat.result)
        return (NULL);

	// generate combination
    if (digitsLen == 1)
    {
        int num = convertNum(digits,0);
        char *buf = malloc(sizeof(char)+1);
        if(!buf)
        {
            free(stat.result);
            return (NULL);
        }
        for(int i=0; i<__sizes[num - 2] ;i++)
        {        
            *buf = __map[num - 2][i];
            stat.result[i] = __strdup(buf,1);
        }

        free(buf);
        *returnSize = combCount;
        return (stat.result);
    }

    stat.comb = (char *)malloc(sizeof(char) * (digitsLen + 1));
    if(!stat.comb)
    {
        free(stat.result);
        return (NULL);
    }
    stat.res_idx = 0;
    generateComb(digits, digitsLen, 0, &stat, &nummap);
    
    free(stat.comb);
    *returnSize = combCount;
    return (stat.result);
}

int main(void)
{
    char    **result;
    char    digits[] = "23";
    int     returnSize, len;

    result  = letterCombinations(digits, &returnSize);

    if(!result)
    {
        printf("(none)\n");
        return (0);
    }

    len     = digitsLenCount(digits);
    for(int i=0; i<returnSize ;i++)
    {
        print_arr(result[i], len);
    }
    arrs_free((void **)result, returnSize);

    return (0);
}