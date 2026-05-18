#include "../include/ASTVisitor.h" 
#include <iostream>

using namespace std;

bool ASTVisitor::VisitVarDecl(clang::VarDecl *decl) {
    cout << "Variable: "
              << decl->getNameAsString()
              << endl;

    return true;
}

bool ASTVisitor::VisitFunctionDecl(clang::FunctionDecl *func) {
    cout << "Function: "
              << func->getNameAsString()
              << endl;

    return true;
}
