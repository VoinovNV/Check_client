#include <stdio.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <optional>
#include <charconv>
#include <sys/wait.h>
std::string get_secret(std::string input){
    char a[]={0,0,0,0,0};
    for(auto k: input) {*reinterpret_cast<unsigned*>(a)+=(k-'!')*getpid()/geteuid();
        *reinterpret_cast<unsigned*>(a)-=(*reinterpret_cast<unsigned*>(a)<< 0x0000000D)|(*reinterpret_cast<unsigned*>(a)>>0x00000013);
    }
    *reinterpret_cast<unsigned*>(a)=(*reinterpret_cast<unsigned*>(a)&0x41482214)|0x41482214;
    std::string output=a;
    return output;
}
template<typename T>
std::optional<T> from_chars(std::string_view sv) noexcept{
    T out;auto end = sv.data()+sv.size();auto res = std::from_chars(sv.data(),end,out);
    if(res.ec==std::errc{}&&res.ptr==end)
        return out;
    return {};
}
bool cmp(std::string password,std::string key){
    auto p = from_chars<std::uint32_t>(password);
    if(!p||!*p) return false;
    int a=*reinterpret_cast<const int*>(key.data());
    return p==a;
}
void action(bool flag){
    if(flag) std::cout<<"Well!\n"; else std::cout<<"Invalid password\n";
}
int main()
{
    switch(fork()){
    case 0:{
        std::string login;
        std::cout << "Input login:\n";
        if(!(std::cin >> login)){std::cout<<"Error! Try again\n"; exit(0);};
        std::string password;
        std::cout << "Input password: ("<<getpid()<<", "<<geteuid()<<")\n";
        if(!(std::cin >> password)){
            std::cout<<"Error!\n";
            exit(0);
        }
        exit(cmp(password,get_secret(login)));}
    case -1: {std::cerr<<"Fork error!"; break;}
    default:
    {
        int res;
        waitpid(-1,&res,0);
        action(WEXITSTATUS(res)>0?1:0);
        break;
    }
    }
    return 0;
}
