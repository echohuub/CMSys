//
//  CourseManager.cpp
//  CMSys
//
//  Created by 何清宝 on 16/1/30.
//  Copyright © 2016年 何清宝. All rights reserved.
//

#include <iostream>
#include "CourseManager.hpp"

using namespace std;

// 构造函数，参数为课程vector
CourseManager::CourseManager(const vector<Course> &courseVect) {
    for (auto curs = courseVect.begin(); curs != courseVect.end(); ++curs) {
        courseList.push_back(*curs);
    }
}

// 添加课程函数（参数为课程对象）
void CourseManager::AddCourse(const Course &course) {
    courseList.push_back(course);
}

// 添加课程函数（参数为课程名称）
void CourseManager::AddCourse(const string &courseName) {
    Course course(courseName);
    courseList.push_back(course);
}

// 删除课程：删除最后一个课程
void CourseManager::RemoveLast() {
    try {
        // 如果课程非空，则删除最后一门课程
        if (!courseList.empty()) {
            courseList.pop_back();
            cout << "Deleted successfully!" << endl;
        } else {
            // 课程为空，则抛异常，该异常将被catch捕获
            throw runtime_error("Deleted error, there is no course!");
        }
    } catch (runtime_error err) {
        cout << err.what() << endl;
    }
}

// 删除课程：删除指定名称的课程
void CourseManager::RemoveByName(const string &name) {
    int index = FindCourse(name);
    
    if (index > 0) {
        courseList.erase(courseList.begin() + index);
    } else {
        cout << "NOT FOUND" << endl;
    }
}

// 删除课程：删除指定ID的课程
void CourseManager::RemoveById(int id) {
    int index = FindCourse(id);
    
    if (index > 0) {
        courseList.erase(courseList.begin() + index);
    } else {
        cout << "NOT FOUND" << endl;
    }
}

// 打印课程列表信息
void CourseManager::PrintAllCourse() {
    cout << "CourseList:" << endl;
    
    // 遍历courseList，打印出所有course信息
    for (auto curs = courseList.begin(); curs != courseList.end(); ++curs) {
        cout << *curs << endl;
    }
}

// 根据课程名称打印指定课程信息
void CourseManager::PrintCourse(const string &name) {
    int index = FindCourse(name);
    
    if (index > 0) {
        cout << courseList[index] << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
}

// 根据课程ID打印指定课程信息
void CourseManager::PrintCourse(int id) {
    int index = FindCourse(id);
    
    if (index > 0) {
        cout << courseList[index] << endl;
    } else {
        cout << "NOT FOUND" << endl;
    }
}

// 打印名称最长的课程
void CourseManager::PrintLongNameCourse() {
    
    int maxLen = 0;
    
    // 遍历courseList，查找最长名称
    for (auto curs = courseList.begin(); curs != courseList.end(); ++curs) {
        int currentLen = static_cast<int>(curs->GetName().size());
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }
    
    
    // 遍历coursetList，打印最长名称课程
    for (auto curs = courseList.begin(); curs != courseList.end(); ++curs) {
        if (curs->GetName().size() == maxLen) {
            cout << *curs << endl;
        }
    }
}

// 根据ID查找课程，返回课程在vector中的索引
int CourseManager::FindCourse(int id) {
    for (int i = 0; i < courseList.size(); i++) {
        if (courseList[i].GetId() == id) {
            return i;
        }
    }
    
    return -1;
}

// 根据名字查找课程，返回课程在vector中的索引
int CourseManager::FindCourse(const string &name) {
    
    int i = 0;
    for (; i < courseList.size(); i++) {
        if (courseList[i].GetName() == name) {
            return i;
        }
    }
    
    return -1;
}