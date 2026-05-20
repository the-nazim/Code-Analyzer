#ifndef ANALYZERCONSUMER_H
#define ANALYZERCONSUMER_H

#include <clang/AST/ASTConsumer.h>
#include <clang/AST/ASTContext.h>

#include "ASTVisitor.h"

class AnalyzerConsumer : public clang::ASTConsumer {

public:
    void HandleTranslationUnit(
        clang::ASTContext &context
    ) override;
};

#endif