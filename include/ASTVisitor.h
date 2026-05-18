#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include <clang/AST/RecursiveASTVisitor.h>

class ASTVisitor : public clang::RecursiveASTVisitor<ASTVisitor> { 

    public:
        bool VisitVarDecl(clang::VarDecl *varDecl);
        bool VisitFunctionDecl(clang::FunctionDecl *funcDecl);
};

#endif