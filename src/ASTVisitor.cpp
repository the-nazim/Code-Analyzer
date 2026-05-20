#include "../include/ASTVisitor.h" 
#include <iostream>

using namespace std;

bool ASTVisitor::VisitVarDecl(clang::VarDecl *decl) {
    if (decl->isImplicit() || !decl->getIdentifier()) {
        return true;
    }

    string variableName = decl->getNameAsString();
    declaredVars.insert(variableName);

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

        string usedName =
            decl->getNameAsString();

        usedVars.insert(usedName);

        cout
            << "Used Variable: "
            << usedName
            << endl;
    }
    return true;
}

void ASTVisitor::ReportUnusedVariables() {
    bool foundUnused = false;

    for (const auto &var : declaredVars) {

        if (usedVars.find(var) == usedVars.end()) {

            if (!foundUnused) {
                cout
                    << "\n=== UNUSED VARIABLES ===\n";
            }

            foundUnused = true;

            cout
                << "Unused Variable: "
                << var
                << endl;
        }
    }

    if (!foundUnused) {
        cout
            << "\nNo unused variables found.\n";
    }
}
