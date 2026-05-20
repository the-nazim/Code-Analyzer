#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include <clang/AST/RecursiveASTVisitor.h>
#include <string>
#include <set>

class ASTVisitor : public clang::RecursiveASTVisitor<ASTVisitor> { 

    private:
        std::set<std::string> declaredVars;
        std::set<std::string> usedVars;

    public:
        bool VisitVarDecl(clang::VarDecl *varDecl);
        bool VisitFunctionDecl(clang::FunctionDecl *funcDecl);
        bool VisitDeclRefExpr(clang::DeclRefExpr *declRef);
        void ReportUnusedVariables();
};

#endif