﻿/*
			This file is part of:
				NoahFrame
			https://github.com/ketoo/NoahGameFrame

   Copyright 2009 - 2021 NoahFrame(NoahGameFrame)

   File creator: lvsheng.huang

   NoahFrame is open-source software and you can redistribute it and/or modify
   it under the terms of the License; besides, anyone who use this file/software must include this copyright announcement.

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

	   http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#include "NFNodeSystem.h"
#include "gl3w/GL/glcorearb.h"
#include "gl3w/GL/gl3w.h"
#include "imgui/imgui.h"
#include "NFSceneSystem.h"


NFSceneSystem::NFSceneSystem()
{
}

NFSceneSystem::~NFSceneSystem()
{
}

void NFSceneSystem::Execute()
{
}

NFVector2 NFSceneSystem::ToSceneGridPos(const NFVector3& pos)
{

    NFVector2 displayOffset((float)(mNodeSystem.GetNodeSize() / 2), (float)(mNodeSystem.GetNodeSize() / 2));

    return NFVector2(pos.X() * mNodeSystem.GetNodeSize() - displayOffset.X(), pos.Z() * -mNodeSystem.GetNodeSize() - displayOffset.Y());
}
