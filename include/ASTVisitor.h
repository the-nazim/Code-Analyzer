#ifndef AST_VISITOR_H
#define AST_VISITOR_H

#include <clang/AST/RecursiveASTVisitor.h>
#include <clang/Basic/SourceManager.h>
#include <llvm/Support/Path.h> 
#include <string>
#include <set>
#include <map>

class ASTVisitor : public clang::RecursiveASTVisitor<ASTVisitor> { 

    private:
        // std::set<std::string> declaredVars;
        clang::ASTContext *context;
        std::set<std::string> usedVars;
        std::map<std::string, clang::VarDecl*> declaredVars;

    public:
        explicit ASTVisitor(clang::ASTContext *ctx);
        bool VisitVarDecl(clang::VarDecl *varDecl);
        bool VisitFunctionDecl(clang::FunctionDecl *funcDecl);
        bool VisitDeclRefExpr(clang::DeclRefExpr *declRef);
        void ReportUnusedVariables();
};

#endif