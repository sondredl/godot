//
// Copyright (C) 2002-2005  3Dlabs Inc. Ltd.
// Copyright (C) 2013 LunarG, Inc.
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
//    Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
//    Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
//    Neither the name of 3Dlabs Inc. Ltd. nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
//

#include "../Include/intermediate.h"
#include "RemoveTree.h"

namespace glslang {

//
// Code to recursively delete the intermediate tree.
//
struct TRemoveTraverser : TIntermTraverser {
    TRemoveTraverser() : TIntermTraverser(false, false, true, false) {}

    void visitSymbol(TIntermSymbol* node) override
    {
        delete node;
    }

    bool visitBinary(TVisit /* visit*/ , TIntermBinary* node) override
    {
        delete node;

        return true;
    }

    bool visitUnary(TVisit /* visit */, TIntermUnary* node) override
    {
        delete node;

        return true;
    }

    bool visitAggregate(TVisit /* visit*/ , TIntermAggregate* node) override
    {
        delete node;

        return true;
    }

    bool visitSelection(TVisit /* visit*/ , TIntermSelection* node) override
    {
        delete node;

        return true;
    }

    bool visitSwitch(TVisit /* visit*/ , TIntermSwitch* node) override
    {
        delete node;

        return true;
    }

    void visitConstantUnion(TIntermConstantUnion* node) override
    {
        delete node;
    }

    bool visitLoop(TVisit /* visit*/ , TIntermLoop* node) override
    {
        delete node;

        return true;
    }

    bool visitBranch(TVisit /* visit*/ , TIntermBranch* node) override
    {
        delete node;

        return true;
    }
};

//
// Entry point.
//
void RemoveAllTreeNodes(TIntermNode* root)
{
    TRemoveTraverser it;

    root->traverse(&it);
}

} // end namespace glslang
