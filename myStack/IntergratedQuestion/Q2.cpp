//
// Created by 姜杰铧 on 2023/10/20.
//
#include <map>
#include <queue>
#include <iostream>
#include <fstream>
const int MaxSize = 1050;
using namespace std;
char cmd[10];//记录命令
int main(){
    ifstream ifs;
    ifs.open("in.txt");
    //团队个数
    int num,person;
    map<int,int>team;
    ifs>>num;
    for(int i = 0; i < num; i++)
    {
        int team_size;
        ifs>>team_size;//每个不同团队的大小

        for(int j = 0; j < team_size; j++)
        {

            ifs>>person;

            team[person] = i;
        }
    }
    queue<int>team_index,teamPerson[MaxSize];
    while(1)
    {
        ifs>>cmd;
        if(cmd[0] == 'S')//结束命令
            break;
        else if(cmd[0] == 'E')//入队命令
        {
            int tmp;//记录临时编号
            ifs>>tmp;
            int id = team[tmp];//找到团队
            if(teamPerson[id].empty())team_index.push(id);//团队没人，加入到最后
            teamPerson[id].push(tmp);
        }
        else
        {
            int t = team_index.front();
            cout<<teamPerson[t].front()<<endl;
            teamPerson[t].pop();
            if(teamPerson[t].empty())
                team_index.pop();//如果踢了之后没人了，出队该团队编号
        }
    }
    ifs.close();
    return 0;
}