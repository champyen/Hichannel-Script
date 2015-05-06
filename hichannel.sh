 #!/bin/sh
RADIO_ID=$1
curl -o play.url http://hichannel.hinet.net/radio/play.do?id=$RADIO_ID
TMP_URL=`cat play.url | cut -d '"' -f 8`
URL_PREFIX=`echo $TMP_URL | cut -d '?' -f 1 | rev | cut -c 11- | rev`
curl -o index.m3u8 $TMP_URL
TMP_FILE=`cat index.m3u8 | cut -d '#' -f 3 | tail -1`

curl -o stream.m3u8 $URL_PREFIX/$TMP_FILE

TMP_FILE=`cat stream.m3u8 | tail -1`
START_SEQ=`echo $TMP_FILE | cut -d '.' -f 1 | cut -d '-' -f 5`
TMP_NUM_LEN=`echo $START_SEQ | wc -c`
TMP_FILE=`echo $TMP_FILE | rev | cut -c $TMP_NUM_LEN- | cut -c 4- | rev`

curl $URL_PREFIX/$TMP_FILE[$START_SEQ-99999].ts | mplayer -vo null -
