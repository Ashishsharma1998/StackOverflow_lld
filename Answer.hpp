#ifndef ANSWER  
#define ANSWER

#include "Comment.hpp"
#include "User.hpp"


#include <vector>
#include <string>

class Question;

class Answer {
private:
    int id;
    int votecount;
    std::string body;
    std::vector<Comment*> comments;
    User *author;
    Question *q;

public:
    Answer(int id, User *author, int votecount,std::string body,std::vector<Comment*> comments,Question *q) {
       this->id=id;
       this->author=author;
       this->votecount=votecount;
       this->body=body;
       this->comments=comments;
       this->q=q; 
    }
        
    void setComment(Comment *com){
        comments.push_back(com);
    }     

    void setVoteCount(int vote) {
        votecount = vote;
    }

    int getId(){
        return id;
    }

    User* getAuthor(){
        return author;
    }

    int getVoteCount(){
        return votecount;
    }

    Question* getQuestion(){
        return q;
    }

    std::string getBody(){
        return body;
    }

    std::vector<Comment*> getComments(){
        return comments;
    }
};

#endif
