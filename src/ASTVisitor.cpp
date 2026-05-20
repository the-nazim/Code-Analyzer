#include "../include/ASTVisitor.h" 
#include <iostream>

using namespace std;

ASTVisitor::ASTVisitor(clang::ASTContext *ctx) : context(ctx) {}

bool ASTVisitor::VisitVarDecl(clang::VarDecl *decl) {
    if (decl->isImplicit() || !decl->getIdentifier()) {
        return true;
    }

    string variableName = decl->getNameAsString();
    declaredVars[variableName] = decl;

    cout << "Variable: "
              << variableName
              << endl;

    return true;
}

bool ASTVisitor::VisitFunctionDecl(clang::FunctionDecl *func) {
    cout << "Function: "
              << func->getNameAsString()
              << endl;

    return true;
}

bool ASTVisitor::VisitDeclRefExpr(clang::DeclRefExpr *exp) {
    auto *decl = llvm::dyn_cast<clang::VarDecl>(
            exp->getDecl()
        );

    if (decl) {

        std::string usedName =
            decl->getNameAsString();

        usedVars.insert(usedName);
    }
    return true;
}

void ASTVisitor::ReportUnusedVariables() {
    auto &sourceManager =
        context->getSourceManager();

    for (const auto &[varName, decl] : declaredVars) {

        if (usedVars.find(varName) == usedVars.end()) {

            clang::SourceLocation loc =
                decl->getLocation();

            clang::FullSourceLoc fullLoc(
                loc,
                sourceManager
            );

            std::cout
                << sourceManager.getFilename(loc).str()
                << ":"
                << fullLoc.getSpellingLineNumber()
                << ":"
                << fullLoc.getSpellingColumnNumber()
                << ": warning: unused variable '"
                << varName
                << "'"
                << std::endl;
        }
    }
}
