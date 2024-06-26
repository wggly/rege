#!/bin/bash
data_server=$(curl -v --insecure --silent https://google.com/ 2>&1 | grep Date | sed -e 's/< Date: //')
date_list=$(date +"%Y-%m-%d" -d "$data_server")
#########################
[[ ! -f /usr/bin/git ]] && apt install git -y &> /dev/null
# COLOR VALIDATION
clear
y='\033[1;93m'
c="\033[0;36m"
g="\e[92;1m"
r="\033[1;31m"
NC='\e[0m'
gray="\e[1;30m"
Blue="\033[1;36m"
GREEN='\033[0;32m'
grenbo="\033[1;95m"
yell='\e[33m'
BGX="\033[42m"
END='\e[0m'
bc="\e[5;36m"
ungu='\033[0;35m'
Green_background="\033[42;37m"
Red_background="\033[41;37m"
Suffix="\033[0m"
NC='\e[0m'

MYIP=$(curl -sS ipv4.icanhazip.com)


TOKEN="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"
REPO="https://github.com/wggly/izin.git"
EMAIL="qrefandi3@gmail.com"
USER="wggly"

TIMES="10"
URL="https://api.telegram.org/bot$KEY/sendMessage"

function lane() {
echo -e "${bc} ————————————————————————————————————————${NC}"
}

function LOGO() {
echo -e ""
lane
echo -e "${ungu}            BOGEL TUNNELING            "
lane
echo -e ""
}

function register() {
echo -e "${ungu}               Register IP              ${Suffix}"
}

function Credit_wggly() {
sleep 1
echo -e "" 
lane
echo -e " ${c}     Terimakasih sudah menggunakan"
echo -e "      Script Credit by BOGEL TUNNELING${NC}"
lane
echo -e ""
exit 0
}

add-ip() {


today=`date -d "0 days" +"%Y-%m-%d"`
git clone ${REPO} /root/izin/ &> /dev/null
clear
echo -e "MASUKAN IP VPS YANG BELUM DI DAFTAR !"
echo -e ""
read -p "Input IP Address : " ip
CLIENT_EXISTS=$(grep -w $ip /root/izin/ipvps | wc -l)
if [[ ${CLIENT_EXISTS} == '1' ]]; then
echo "IP Already Exist !"
exit 0
fi
echo -e ""
 read -p "  MASUKKAN USERNAME TANPA SPASI (Example : BogelStore) : " name
#name=F6EPQtYeJ3DmRZaL`</dev/urandom tr -dc A-Z0-9 | head -c4`
echo -e ""
clear
echo -e " ${r} Sett Waktu Expired${NC}"
echo -e "  ${y} 1.${NC}${c} 30 Days${NC}"
echo -e "  ${y} 2.${NC}${c} 60 Days${NC}"
echo -e "  ${y} 3.${NC}${c} 90 Days${NC}"
echo -e "  ${y} 4.${NC}${c} Lifetime${NC}"
echo -e "  ${y} 5.${NC}${c} Custom Expiration Date${NC}"
echo -e ""
read -p "Select Number 1 - 5 : " exp

if [[ ${exp} == '1' ]]; then
exp2=`date -d "30 days" +"%Y-%m-%d"`
echo "### ${name} ${exp2} ${ip}" >> /root/izin/ipvps
elif [[ ${exp} == '2' ]]; then
exp2=`date -d "60 days" +"%Y-%m-%d"`
echo "### ${name} ${exp2} ${ip}" >> /root/izin/ipvps
elif [[ ${exp} == '3' ]]; then
exp2=`date -d "90 days" +"%Y-%m-%d"`
echo "### ${name} ${exp2} ${ip}" >> /root/izin/ipvps
elif [[ ${exp} == '4' ]]; then
exp2=`date -d "360 days" +"%Y-%m-%d"`
echo "### ${name} ${exp2} ${ip}" >> /root/izin/ipvps
elif [[ ${exp} == '5' ]]; then
read -p "Input Expired Days : " exp11
exp2=`date -d "$exp11 days" +"%Y-%m-%d"`
echo "### ${name} ${exp2} ${ip}" >> /root/izin/ipvps
fi
cd /root/izin
git config --global user.email "${EMAIL}" &> /dev/null
git config --global user.name "${USER}" &> /dev/null
rm -rf .git &> /dev/null
git init &> /dev/null
git add . &> /dev/null
git commit -m register &> /dev/null
git branch -M main &> /dev/null
git remote add origin https://github.com/wggly/izin
git push -f https://${TOKEN}@github.com/${USER}/izin.git &> /dev/null
rm -rf /root/izin
clear
sleep 1
echo "  Registering IP Address..."
sleep 1
echo "  Done!"
sleep 1
CHATID="6752163466"
KEY="7090971696:AAFGsA1E2_ud_sdU8JdF47B_8GBqxhVHDCw"
URL="https://api.telegram.org/bot$KEY/sendMessage"
TIMEZONE=$(printf '%(%H:%M:%S)T')
TEXT="
<code>────────────────────</code>
<b>⛈️ NOTIFICATION REGISTER IP ⛈️</b>
<code>────────────────────</code>
<code>Ip           :</code><code>$ip</code>
<code>User      :</code><code>$name</code>
<code>Expired :</code><code>$exp2</code>
<code>────────────────────</code>
<i>Automatic Notifications From</i>
<i>BOGEL TUNNELING REGISTRATION </i>
<code>────────────────────</code>
"'&reply_markup={"inline_keyboard":[[{"text":" ⛈️ BUY HERE ⛈️ ","url":"https://t.me/BogelStore1"}]]}' 

curl -s --max-time 10 -d "chat_id=$CHATID&disable_web_page_preview=1&text=$TEXT&parse_mode=html" $URL >/dev/null
clear
lane
echo -e "${g}         SUCCESS ADD IP VPS      $NC"
lane
echo -e "${y}  USERNAME   :${NC}${yell} $name ${NC}"
echo -e "${y}  IP ADDRESS :${NC}${yell} $ip ${NC}"
echo -e "${y}  REGISTERED :${NC}${yell} $today ${NC}"
echo -e "${y}  EXPIRED ON :${NC}${yell} $exp2 ${NC}"
lane
Credit_wggly
}

del-ip() {

    rm -rf /root/izin
    git clone ${REPO} /root/izin/ &> /dev/null
    clear
    echo ""
    lane
    echo -e "${g}         LIST IP VPS          $NC"
    lane
    grep -E "^###" "/root/izin/ipvps" | cut -d ' ' -f 2-6 | column -t | sort | uniq
    grep -E "^#&"  "/root/izin/ipvps" | cut -d ' ' -f 2-6 | column -t | sort | uniq
    lane

    read -p "Input IP Address To Delete : " ipdel
    name=$(cat /root/izin/ipvps | grep $ipdel | awk '{print $2}')
    exp=$(cat /root/izin/ipvps | grep $ipdel | awk '{print $3}')
    if [[ ${exp} == 'Lifetime' ]]; then
    sed -i "/^#&   $name   $exp $ipdel/,/^},{/d" /root/izin/ipvps
    else
    sed -i "/^### $name $exp $ipdel/,/^},{/d" /root/izin/ipvps
    fi
    cd /root/izin
    git config --global user.email "${EMAIL}" &> /dev/null
    git config --global user.name "${USER}" &> /dev/null
    rm -rf .git &> /dev/null
    git init &> /dev/null
    git add . &> /dev/null
    git commit -m register &> /dev/null
    git branch -M main &> /dev/null
    git remote add origin https://github.com/wggly/izin
git push -f https://${TOKEN}@github.com/${USER}/izin.git &> /dev/null
rm -rf /root/izin
    clear
    sleep 1
    echo "  Delete IP Address..."
    sleep 1
    echo "  Processing..."
    sleep 1
    echo "  Done!"
    sleep 1
    CHATID="6752163466"
KEY="7090971696:AAFGsA1E2_ud_sdU8JdF47B_8GBqxhVHDCw"
URL="https://api.telegram.org/bot$KEY/sendMessage"
TIMEZONE=$(printf '%(%H:%M:%S)T')
TEXT="
<code>────────────────────</code>
<b>⛈️ NOTIFICATION DELETE IP ⛈️</b>
<code>────────────────────</code>
<code>Ip           :</code><code>$ipdel</code>
<code>User      :</code><code>$name</code>
<code>Expired :</code><code>$exp</code>
<code>────────────────────</code>
<i>Automatic Notifications From</i>
<i>FREE TUNNELING REGISTRATION </i>
<code>────────────────────</code>
"'&reply_markup={"inline_keyboard":[[{"text":" ⛈️ BUY HERE ⛈️ ","url":"https://t.me/BogelStore1"}]]}' 

curl -s --max-time 10 -d "chat_id=$CHATID&disable_web_page_preview=1&text=$TEXT&parse_mode=html" $URL >/dev/null

    clear
lane
echo -e "${g}      DONE DELETE IP VPS      $NC"
lane
echo -e "${y} USERNAME   :${NC}${yell} $name"
echo -e "${y} IP ADDRESS :${NC}${yell} $ipdel"
echo -e "${y} EXPIRED ON :${NC}${yell} $exp"
lane
Credit_wggly
echo -e ""
}

renew-ip() {

rm -rf /root/izin
git clone ${REPO} /root/izin/ &> /dev/null
clear
lane
echo -e "${g}        RENEW IP VPS      $NC"
lane
grep -E "^###" "/root/izin/ipvps" | cut -d ' ' -f 2-6 | column -t | sort | uniq
lane
echo ""
read -p "  Input IP Address To Renew : " ipdel
read -p "  Input Days  : " days
name=$(cat /root/izin/ipvps | grep $ipdel | awk '{print $2}')
exp=$(cat /root/izin/ipvps | grep $ipdel | awk '{print $3}')
now=$(date +%Y-%m-%d)
d1=$(date -d "$exp" +%s)
d2=$(date -d "$now" +%s)
exp2=$(( (d1 - d2) / 86400 ))
exp3=$(($exp2 + $days))
exp4=`date -d "$exp3 days" +"%Y-%m-%d"`
sed -i "s/### $name $exp $ipdel/### $name $exp4 $ipdel/g" /root/izin/ipvps
cd /root/izin
git config --global user.email "${EMAIL}" &> /dev/null
git config --global user.name "${USER}" &> /dev/null
rm -rf .git &> /dev/null
git init &> /dev/null
git add . &> /dev/null
git commit -m register &> /dev/null
git branch -M main &> /dev/null
git remote add origin https://github.com/wggly/izin
git push -f https://${TOKEN}@github.com/${USER}/izin.git &> /dev/null
rm -rf /root/izin
clear
sleep 1
echo "  Renew IP Address..."
sleep 1
echo "  Processing..."
sleep 1
echo "  Done!"
sleep 1
CHATID="6752163466"
KEY="7090971696:AAFGsA1E2_ud_sdU8JdF47B_8GBqxhVHDCw"
URL="https://api.telegram.org/bot$KEY/sendMessage"
TIMEZONE=$(printf '%(%H:%M:%S)T')
TEXT="
<code>────────────────────</code>
<b>⛈️ NOTIFICATION RENEW IP ⛈️</b>
<code>────────────────────</code>
<code>Ip           :</code><code>$ipdel</code>
<code>User      :</code><code>$name</code>
<code>Expired :</code><code>$exp4</code>
<code>────────────────────</code>
<i>Automatic Notifications From</i>
<i>FREE TUNNELING REGISTRATION </i>
<code>────────────────────</code>
"'&reply_markup={"inline_keyboard":[[{"text":" ⛈️ BUY HERE ⛈️ ","url":"https://t.me/BogelStore1"}]]}' 

curl -s --max-time 10 -d "chat_id=$CHATID&disable_web_page_preview=1&text=$TEXT&parse_mode=html" $URL >/dev/null
clear
echo ""
lane
echo -e "${g}         DONE RENEW IP VPS      $NC"
lane
echo -e "${y}  USERNAME   :${NC}${yell} $name"
echo -e "${y}  IP ADDRESS :${NC}${yell} $ipdel"
echo -e "${y}  EXPIRED ON :${NC}${yell} $exp4"
lane
Credit_wggly
echo -e ""
}

clear
lane
register
lane
echo -e " $bc User Reseller :${NC}${r} $SELLER"$NC
echo -e " $bc Exp Reseller  :${NC}${r} $Exp ${y}(${g} $dayleft ${y})"$NC
lane
echo -e " $g 1.$NC ${c}ADD IP VPS "$NC     
echo -e " $g 2.$NC ${c}DELETE IP VPS"$NC
echo -e " $g 3.$NC ${c}RENEW IP VPS"$NC
echo -e " $g x.$NC ${c}Back To menu"$NC
lane
echo ""
read -p " Select From Options [1 - 3 or x] : " menu
case $menu in
1 | 01)
clear
add-ip
;;
2 | 02)
clear
del-ip
;;
3 | 03)
clear
renew-ip
;;
4 | 04)
menu
;;
*)
exit
;;
esac
