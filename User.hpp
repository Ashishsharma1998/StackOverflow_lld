#ifndef USER_HPP
#define USER_HPP
#include<string>

class User{
 private:
    int id;
    std::string username , email , password;
    int reputation;

 public:
    User(int id,std::string username ,std::string email,std::string password,int reputation){
    this->id=id;
    this->username=username;
    this->email=email;
    this->password=password;
    this->reputation=reputation;
    }   
    
    void setReputation(int reputation){
      this->reputation=reputation;
    }

    std::string getUsername(){
        return username;
    }

    int getId(){
        return id;
    }

    std::string getEmail(){
        return email;
    }
    std::string getPassword(){
        return password;
    }
    int getReputation(){
        return reputation;
    }
};

#endif