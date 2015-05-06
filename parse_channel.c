/*
 get radio station list from
 http://hichannel.hinet.net/radio/channelList.do?radioType=TYPE_ID
 TYPE_ID:
 1 - 音樂
 4 - 生活資訊
 0 - 新聞
 7 - 綜合
 3 - 外語
 5 - 多元文化
 6 - 交通
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
void main(int argc, char** argv)
{
        char *ch_list = malloc(10000);
        FILE *fptr = fopen(argv[1], "r");
        char *pos = ch_list;
 
        fread(ch_list, 10000, 1, fptr);
 
        while(1){
                char *name;
                char *id;
                pos = strstr(pos, "channel_title");
                if(pos == NULL)
                        break;
                name = strchr(pos, '"')+3;
                pos = strchr(name, '"');
                *pos++ = 0;
 
                pos = strstr(pos, "channel_id");
                id = strchr(pos, '"')+3;
                pos = strchr(id, '"');
                *pos++ = 0;
 
                printf("%s:%s\n", name, id);
        }
 
        free(ch_list);
        fclose(fptr);
}
