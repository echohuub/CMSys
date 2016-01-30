//
//  main.cpp
//  CMSys
//
//  Created by 何清宝 on 16/1/30.
//  Copyright © 2016年 何清宝. All rights reserved.
//

#include <iostream>
#include "CmdManager.hpp"

int main(int argc, const char * argv[]) {
    
    // 输入的命令
    int cmd;
    
    // 创建命令管理对象
    CmdManager cmdManager;
    cmdManager.Init();
    
    // 打印帮助信息
    cmdManager.PrintAllHelp();
    
    cout << "New Comand:";
    
    // 进入主循环并处理输入信息
    while (cin >> cmd) {
        if (cin.good()) {
            bool exitCode = cmdManager.HandleCmd(static_cast<CourseCmd>(cmd));
            if (!exitCode) {
                return 0;
            }
            
            cout << "----------------------------------------" << endl;
            cout << "New Command:";
            
            // 清理输入流，避免刚才流中的字符影响后续输入
            cin.clear();
            cin.ignore();
        }
    }
    return 0;
}
