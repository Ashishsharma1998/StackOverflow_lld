#ifndef STACKOVERFLOW_HPP
#define STACKOVERFLOW_HPP

#include "Question.hpp"
#include "Answer.hpp"
#include "Tag.hpp"
#include "User.hpp"

#include <map>
#include <vector>
#include <string>
#include <iostream>


class StackOverflow {
private:
    static StackOverflow *instance;
    std::map<int, Question*> questions;
    std::map<int, User*> users;
    std::map<std::string, std::vector<Question*>> taggedQuestions;

    StackOverflow() {
        std::cout<<"instance created "<<std::endl;
    }

public:
    static StackOverflow* getInstance() {
        if (instance == nullptr) {
            instance = new StackOverflow();
        }
        return instance;
    }

    void registerUser(User *user) {
        users[user->getId()] = user;
    }

    User* loginUser(const std::string &username, const std::string &password) {
        for (auto usr : users) {
            if (usr.second->getUsername() == username && usr.second->getPassword() == password) {
                return usr.second;
            }
        }
        return nullptr;
    }

    void postQuestion(Question *ques) {
        questions[ques->getId()] = ques;
        for (Tag *tg : ques->getTags()) {
            taggedQuestions[tg->getTag()].push_back(ques);
        }
    }

    void postAnswer(Answer *ans) {
        Question *ques = ans->getQuestion();
        ques->setAnswer(ans);
    }

    void postCommentOnAnswer(Comment *com,Answer *ans) {
        ans->setComment(com);
    }
    
    void postCommentOnQuestion(Comment *com,Question *q){
        q->setComment(com);
    }
    
    std::vector<Comment*>getCommentOnQuestion(Question *q){
        return q->getComments();
    }

    std::vector<Comment*>getCommentOnAnswer(Answer *ans){
        return ans->getComments();
    }


    std::vector<Answer*> getAnswer(Question *q){
       return q->getAnswers();
    }


    void voteQuestion(Question *q, int vote) {
        q->setVoteCount(q->getVoteCount() + vote);
        q->getAuthor()->setReputation(q->getAuthor()->getReputation() + vote);
    }

    void voteAnswer(Answer *ans, int vote) {
        ans->setVoteCount(ans->getVoteCount() + vote);
        ans->getAuthor()->setReputation(ans->getAuthor()->getReputation() + vote);
    }

    std::vector<Question*> searchQuestions(const std::string &query){
        std::vector<Question*> res;
        for (auto &q : questions) {
            if (q.second->getTitle().find(query) != std::string::npos || q.second->getBody().find(query) != std::string::npos) {
                res.push_back(q.second);
            }
        }
        return res;
    }

    std::vector<Question*> searchByTagName(const std::string &tagName){
        auto it = taggedQuestions.find(tagName);
        if (it != taggedQuestions.end()) {
            return it->second;
        }
        return {};
    }

    std::vector<Question*> getQuestionsByUser(User *usr){
        std::vector<Question*> res;
        for (const auto &q : questions) {
            if (q.second->getAuthor() == usr) {
                res.push_back(q.second);
            }
        }
        return res;
    }
};

StackOverflow* StackOverflow::instance = nullptr;

#endif
