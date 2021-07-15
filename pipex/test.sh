#! /bin/bash
S1="================================================================================"
S2="--------------------------------------------------------------------------------"
GREEN="\033[38;2;57;181;74m"
RED="\033[38;2;222;56;43m"
BLUE="\033[38;2;34;183;235m"
YELLOW="\033[38;2;255;176;0m"
PURPLE="\033[38;2;255;105;180m"
RESET="\033[0m"
comp() {
    printf "$RED";
    diff -u $1 $2;
    printf "$RESET"
    if [ $? -eq 0 ]; then
        printf "$GREEN""OK !$RESET\n"
    fi
}
echo -n "hello\nhello world\nhell\na1a1a1\na1\na2\na3a4\n\a1\n" > test1
echo -n "hello\nhello world\nhell\na1a1a1\na1\na2\na3a4\n\a1\n" > user1
echo -n "mrdocmrdoc" > tcase1
echo -n "mrdocmrdoc" > ucase1
printf "$YELLOW$S1\n\n"
echo "██████╗ ██╗██████╗ ███████╗██╗  ██╗    ███╗   ███╗███████╗██████╗ ██╗ ██████╗"
echo "██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝    ████╗ ████║██╔════╝██╔══██╗██║██╔════╝"
echo "██████╔╝██║██████╔╝█████╗   ╚███╔╝     ██╔████╔██║█████╗  ██║  ██║██║██║     "
echo "██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗     ██║╚██╔╝██║██╔══╝  ██║  ██║██║██║     "
echo "██║     ██║██║     ███████╗██╔╝ ██╗    ██║ ╚═╝ ██║███████╗██████╔╝██║╚██████╗"
echo "╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝    ╚═╝     ╚═╝╚══════╝╚═════╝ ╚═╝ ╚═════╝"
printf "\n$S1$RESET\n"
printf "$BLUE"; make -C ../ all; printf "$RESET"
printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile grep hello | awk '{count++} END {print count}' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep hello | awk '{count++} END {print count}' > test2 2> test2
../pipex/pipex user1 "grep hello" "awk '{count++} END {print count}'" user2 2> user2
comp test2 user2
printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile ls -tUmp | cat -e > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 ls -tUmp | cat -e > test2 2> test2
../pipex/pipex user1 "ls -tUmp" "cat -e" user2 2> user2
comp test2 user2
rm -rf test2 user2
printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile git ls-files --others -i --exclude-standard | cat -e > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 git ls-files --others -i --exclude-standard | cat -e > test2 2> test2
../pipex/pipex user1 "git ls-files --others -i --exclude-standard" "cat -e" user2 2> user2
comp test2 user2
rm -rf test2 user2
printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile find . -type f \( -name \"#*#\" -o -name \"*~\" -o -name \"#\" \) -exec rm -v {} \; | cat -e > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
touch txt~~
< test1 find . -type f \( -name "#*#" -o -name "*~" -o -name "#" \) -exec rm -v {} \; | cat -e > test4 2> test4
touch txt~~
../pipex/pipex user1 "find . -type f ( -name \"#*#\" -o -name \"*~\" -o -name \"#\" ) -exec rm -v {} ;" "cat -e" user4 2> user4
comp test4 user4
#rm -rf test4 user4
printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""test: < infile groups \$FT_USER | tr ' ' ',' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 groups $FT_USER | tr ' ' ',' > test5 2> test5
../pipex/pipex user1 "groups $FT_USER" "tr ' ' ','" user5 2> user5
comp test5 user5
rm -rf test5 user5
printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""find . -type f -name "*.sh" -exec basename {} .sh \; | tr ' ' ',' > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 find . -type f -name "*.sh" -exec basename {} .sh \; | tr ' ' ',' > test6 2> test6
../pipex/pipex user1 "find . -type f -name \"*.sh\" -exec basename {} .sh ;" "tr ' ' ','" user6 2> user6
comp test6 user6
rm -rf test6 user6
printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""< tcase cat | tr "mrdoc" "01234" > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< tcase1 cat | tr "mrdoc" "01234" > test7 2> test7
../pipex/pipex ucase1 "cat" "tr \"mrdoc\" \"01234\"" user7 2> user7
comp test7 user7
rm -rf test7 user7
printf "$YELLOW$S1$RESET\n"
printf "$PURPLE""< test1 grep a1 | wc -w > outfile$RESET\n"
printf "$PURPLE$S2$RESET\n"
< test1 grep a1 | wc -w > test8 2> test8
../pipex/pipex user1 "grep a1" "wc -w" user8 2> user8
comp test8 user8
rm -rf test1 user1
rm -rf tcase1 ucase1
printf "\033[38;2;255;176;0m\n%80s\n%80s\n%80s\033[0m\n" "Test finished." "@2021, Pipex Medic."
