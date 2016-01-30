//
//  CmdManager.hpp
//  CMSys
//
//  Created by 何清宝 on 16/1/30.
//  Copyright © 2016年 何清宝. All rights reserved.
//

#ifndef CmdManager_hpp
#define CmdManager_hpp

#include <map>
#include <istream>

#include "CourseManager.hpp"
#include "Cmd.h"

using namespace std;

// 命令管理类
class CmdManager {
    
public:
    // 构造函数
    CmdManager() = default;
    
    // 初始化函数，初始化支持的命令及课程信息
    void Init();
    
    // 打印帮助信息
    void PrintAllHelp() const;
    
    // 根据命令查询帮助信息
    void PrintCmdHelp(const CourseCmd cmd) const;
    
    // 处理命令操作
    bool HandleCmd(const CourseCmd cmd);
    
    // 返回课程管理对象
    CourseManager& GetCourseManager() { return manager; };

private:
    // 课程管理对象
    CourseManager manager;
    
    // 使用map存储命令及帮助信息
    map<CourseCmd, string> cmdMap;
};

#endif /* CmdManager_hpp */
