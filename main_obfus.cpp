#include<stdio.h>
#include<iostream>
#include<string>
#include<unistd.h>
#include<optional>
#include<charconv>
#include<sys/wait.h>
std::string Ox12587796(std::string input){char Ox27546895[]={0,0,0,0,0};for(auto k:input){Ox12766512(Ox27546895)+=(k-'!')*getpid()/geteuid();
Ox12766512(Ox27546895)-=(Ox12766512(Ox27546895)<<0x0000000D)|(Ox12766512(Ox27546895)>>0x00000013);
}Ox12766512(Ox27546895)=(Ox12766512(Ox27546895)&0x41482214)|0x41482214;
std::string output=Ox27546895;return output;}
template<typename T>
std::optional<T> from_chars(std::string_view sv)noexcept{T out;auto end=sv.data()+sv.size();auto res=std::from_chars(sv.data(),end,out);
if(res.ec==std::errc{}&&res.ptr==end)return out;return{};}
bool Ox12146682(std::string Ox1645A55A,std::string Ox3324FAA4){auto Ox95A5D121=from_chars<std::uint32_t>(Ox1645A55A);
if(!Ox95A5D121||!*Ox95A5D121)return false;int Ox95A52221=*reinterpret_cast<const int*>(Ox3324FAA4.data());return Ox95A5D121==Ox95A52221;}
void Ox12215456(bool flag){if(flag)std::cout<<"Well!\n";else std::cout<<"Invalid password\n";}int main()
{switch(fork()){case 0:{std::string Ox4187DE12;std::cout<<"Input login:\n";if(!(std::cin>>Ox4187DE12))
{std::cout<<"Error!\n";exit(0);};std::string Ox845621DA;
std::cout<<"Input password:( "<<getpid()<<", "<<geteuid()<<")\n";if(!(std::cin>>Ox845621DA)){std::cout<<"Error!\n";exit(0);}
exit(Ox12146682(Ox845621DA,Ox12587796(Ox4187DE12)));}case -1:{std::cerr<<"Fork error!";break;}default:{int Ox76529183;waitpid(-1,&Ox76529183,0);
Ox12215456(WEXITSTATUS(Ox76529183)>0?1:0);break;}}return 0;}
