#ifndef QUESTION
#define QUESTION

#include "Comment.hpp"
#include "User.hpp"
#include "Tag.hpp"
#include "Answer.hpp"
#include<vector>

class Question{
  private:
    int id;
    User *author;
    int votecount;
    std::string body;
    std::string title;
    std::vector<Comment*> comments;
    std::vector<Answer*> answers;
    std::vector<Tag*> tags;

  public:
     Question(int id,User* author,int count,std::string body,std::string title,std::vector<Comment*> comments,std::vector<Answer*> answers,std::vector<Tag*> tags){
          this->id=id;
          this->author=author;
          this->votecount=count;
          this->body=body;
          this->title=title;
          this->comments=comments;
          this->tags=tags;
          this->answers=answers;
     }  
    
    void setAnswer(Answer *ans){
      answers.push_back(ans);
    }

     void setVoteCount(int vote){
       votecount=vote;
     }

      void setComment(Comment *com){
        comments.push_back(com);
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

     std::string getBody(){
        return body;
     }

     std::string getTitle(){
        return title;
     }

     std::vector<Comment*> getComments(){
        return comments;
     }

     std::vector<Tag*> getTags(){
        return tags;
     }

     std::vector<Answer*> getAnswers(){
        return answers;
     }

};

#endif