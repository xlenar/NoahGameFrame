/*
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

#include "NFUIModule.h"
#include "NFContainerView.h"
#include "NFBluePrintView.h"

NFContainerView::NFContainerView(NFIPluginManager* p, NFViewType vt) : NFIView(p, vt, GET_CLASS_NAME(NFContainerView))
{
   m_pUIModule = pPluginManager->FindModule<NFIUIModule>();

   m_pElementModule = pPluginManager->FindModule<NFIElementModule>();
   m_pClassModule = pPluginManager->FindModule<NFIClassModule>();
}

void NFContainerView::FileMenu()
{
   if (ImGui::BeginMenu("File"))
   {
      // Disabling fullscreen would allow the window to be moved to the front of other windows,
      // which we can't undo at the moment without finer window depth/z control.
      //ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

      if (ImGui::MenuItem("Open", ""))
      {

      }
      if (ImGui::MenuItem("Save", ""))
      {
                  
      }
      if (ImGui::MenuItem("Close", ""))
      {
                  
      }
      //ImGui::Separator();
      ImGui::EndMenu();
   }
}

void NFContainerView::EditMenu()
{
   if (ImGui::BeginMenu("Edit"))
   {
      // Disabling fullscreen would allow the window to be moved to the front of other windows,
      // which we can't undo at the moment without finer window depth/z control.
      //ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

      if (ImGui::MenuItem("Open", ""))
      {

      }
      if (ImGui::MenuItem("Save", ""))
      {
                  
      }
      if (ImGui::MenuItem("Close", ""))
      {
                  
      }
      //ImGui::Separator();
      ImGui::EndMenu();
   }
}

void NFContainerView::PrefabMenu()
{
   if (ImGui::BeginMenu("MetaClass"))
   {
      // Disabling fullscreen would allow the window to be moved to the front of other windows,
      // which we can't undo at the moment without finer window depth/z control.
      //ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);
       auto classObject = m_pClassModule->First();
       while (classObject)
       {
           if (ImGui::BeginMenu(classObject->GetClassName().c_str()))
           {
               if (ImGui::MenuItem("Design", ""))
               {

               }
               if (ImGui::MenuItem("Add a new Element", ""))
               {

               }
               ImGui::EndMenu();
           }

           classObject = m_pClassModule->Next();
       }

      //ImGui::Separator();
      ImGui::EndMenu();
   }
}

void NFContainerView::ElementMenu()
{
   if (ImGui::BeginMenu("Element"))
   {
       auto classObject = m_pClassModule->First();
       while (classObject)
       {
           if (ImGui::BeginMenu(classObject->GetClassName().c_str()))
           {
               auto objects = classObject->GetIDList();
               
               for (int i = 0; i < objects.size(); ++i)
               {
                   if (ImGui::MenuItem(objects[i].c_str(), ""))
                   {
                   }
               }

               ImGui::EndMenu();
           }

           classObject = m_pClassModule->Next();
       }

      //ImGui::Separator();
      ImGui::EndMenu();
   }
}

void NFContainerView::BluePrintMenu()
{
	if (ImGui::BeginMenu("BluePrint"))
	{
		NF_SHARE_PTR<NFIView> p = m_pUIModule->GetView(NFViewType::BluePrintView);
		NF_SHARE_PTR<NFBluePrintView> pBluePrintView = std::dynamic_pointer_cast<NFBluePrintView>(p);
		if (pBluePrintView)
		{
			if (ImGui::MenuItem("New Logic Block", ""))
			{
				pBluePrintView->TryToCreateBluePrintBlock();
			}

			if (ImGui::BeginMenu("New Monitor"))
			{
                for (auto x : NFMonitorType::allValues())
                {
                    if (ImGui::MenuItem(x.toString().c_str(), ""))
                    {
                        pBluePrintView->TryToCreateMonitor(x);
                    }
                }

                ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("New Branch", ""))
			{
                for (auto x : NFBranchType::allValues())
                {
                    if (ImGui::MenuItem(x.toString().c_str(), ""))
                    {
                        pBluePrintView->TryToCreateBranch(x);
                    }
                }

                ImGui::EndMenu();
			}

            if (ImGui::BeginMenu("New Executor"))
            {
                for (auto x : NFExecutorType::allValues())
                {
                    if (ImGui::MenuItem(x.toString().c_str(), ""))
                    {
                        pBluePrintView->TryToCreateExecutor(x);
                    }
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("New Arithmetic"))
            {
				if (ImGui::MenuItem("Arithmetic", ""))
				{
					pBluePrintView->TryToCreateArithmetic(NFArithmeticType::Add);
				}

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("New Modifier"))
            {
                for (auto x : NFModifierType::allValues())
                {
                    if (ImGui::MenuItem(x.toString().c_str(), ""))
                    {
                        pBluePrintView->TryToCreateModifier(x);
                    }
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("New Variable"))
            {
                for (auto x : NFVariableType::allValues())
                {
                    if (ImGui::MenuItem(x.toString().c_str(), ""))
                    {
                        pBluePrintView->TryToCreateVariable(x);
                    }
                }

                ImGui::EndMenu();
            }

            if (ImGui::BeginMenu("New Debugger"))
            {
                if (ImGui::MenuItem("Debugger", ""))
                {
                    pBluePrintView->TryToCreateDebuger();
                }

                ImGui::EndMenu();
            }
            
            if (ImGui::BeginMenu("Custom Variable"))
            {
                for (auto x : NFVariableType::allValues())
                {
                    if (ImGui::MenuItem(x.toString().c_str(), ""))
                    {
                        pBluePrintView->TryToCreateVariable(x);
                    }
                }


                if (ImGui::BeginMenu("New Custom Variable"))
                {
                    for (auto x : NFVariableType::allValues())
                    {
                        if (ImGui::MenuItem(x.toString().c_str(), ""))
                        {
                            pBluePrintView->TryToCreateVariable(x);
                        }
                    }

                    ImGui::EndMenu();
                }

                ImGui::EndMenu();
            }
			//ImGui::Separator();
		}

        ImGui::EndMenu();
	}
}

void NFContainerView::ToolsMenu()
{
   if (ImGui::BeginMenu("Tools"))
   {
      // Disabling fullscreen would allow the window to be moved to the front of other windows,
      // which we can't undo at the moment without finer window depth/z control.
      //ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

      if (ImGui::MenuItem("Transfer meta-class as c++ and c# code", ""))
      {

      }
      if (ImGui::MenuItem("Generate protocol buf as c++ and c# code", ""))
      {
                  
      }
      //ImGui::Separator();
      ImGui::EndMenu();
   }
}

void NFContainerView::WindowsMenu()
{
   if (ImGui::BeginMenu("Windows"))
   {
      NFIUIModule* pModule = pPluginManager->FindModule<NFIUIModule>();
      if (pModule)
      {
         const std::vector<NF_SHARE_PTR<NFIView>>& viewList = pModule->GetViews();
         for (auto item : viewList)
         {
            if (item->viewType != NFViewType::ContainerView
            && item->viewType != NFViewType::OperatorView)
            {
               if (ImGui::MenuItem(item->name.c_str(), "", item->visible))
               {
                  item->visible = !item->visible;
               }
            }
         }
      }
      
      //ImGui::Separator();
      ImGui::EndMenu();
   }
}

void NFContainerView::HelpMenu()
{
   if (ImGui::BeginMenu("Help"))
   {
      // Disabling fullscreen would allow the window to be moved to the front of other windows,
      // which we can't undo at the moment without finer window depth/z control.
      //ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

      if (ImGui::MenuItem("About NoahGameFrame", ""))
      {

      }
      if (ImGui::MenuItem("About element system", ""))
      {
                  
      }
      if (ImGui::MenuItem("About meta-class(prefab) system", ""))
      {

      }
      if (ImGui::MenuItem("About blue print editor", ""))
      {

      }
      //ImGui::Separator();
      ImGui::EndMenu();
   }
}

bool NFContainerView::Execute()
{

   if (visible)
   {
      static ImGuiDockNodeFlags dockspace_flags = ImGuiDockNodeFlags_None;

      //SDL_GetWindowSize(window, &width, &height);
      ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
      ImGuiViewport* viewport = ImGui::GetMainViewport();
      ImGui::SetNextWindowPos(viewport->Pos);
      ImGui::SetNextWindowSize(viewport->Size);
      ImGui::SetNextWindowViewport(viewport->ID);
      ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
      ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
      window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove;
      window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

      // When using ImGuiDockNodeFlags_PassthruCentralNode, DockSpace() will render our background and handle the pass-thru hole, so we ask Begin() to not render a background.
      if (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode)
         window_flags |= ImGuiWindowFlags_NoBackground;

      // Important: note that we proceed even if Begin() returns false (aka window is collapsed).
      // This is because we want to keep our DockSpace() active. If a DockSpace() is inactive,
      // all active windows docked into it will lose their parent and become undocked.
      // We cannot preserve the docking relationship between an active window and an inactive docking, otherwise
      // any change of dockspace/settings would lead to windows being stuck in limbo and never being visible.
      ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));

	  ImGui::Begin(GET_CLASS_NAME(NFContainerView), &visible, window_flags);
      ImGui::PopStyleVar();
      ImGui::PopStyleVar(2);

         // DockSpace
      ImGuiIO& io = ImGui::GetIO();
      if (io.ConfigFlags & ImGuiConfigFlags_DockingEnable)
      {
         ImGuiID dockspace_id = ImGui::GetID("MyDockSpace");
         ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), dockspace_flags);
      }
      else
      {
         //ShowDockingDisabledMessage();
      }

      if (ImGui::BeginMenuBar())
      {
         FileMenu();
         //EditMenu();
         PrefabMenu();
         ElementMenu();
         BluePrintMenu();
         ToolsMenu();
         //WindowsMenu();
         HelpMenu();
         /*
         if (ImGui::BeginMenu("Docking"))
         {
               // Disabling fullscreen would allow the window to be moved to the front of other windows,
               // which we can't undo at the moment without finer window depth/z control.
               //ImGui::MenuItem("Fullscreen", NULL, &opt_fullscreen_persistant);

               if (ImGui::MenuItem("Flag: NoSplit",                "", (dockspace_flags & ImGuiDockNodeFlags_NoSplit) != 0))                 dockspace_flags ^= ImGuiDockNodeFlags_NoSplit;
               if (ImGui::MenuItem("Flag: NoResize",               "", (dockspace_flags & ImGuiDockNodeFlags_NoResize) != 0))                dockspace_flags ^= ImGuiDockNodeFlags_NoResize;
               if (ImGui::MenuItem("Flag: NoDockingInCentralNode", "", (dockspace_flags & ImGuiDockNodeFlags_NoDockingInCentralNode) != 0))  dockspace_flags ^= ImGuiDockNodeFlags_NoDockingInCentralNode;
               if (ImGui::MenuItem("Flag: PassthruCentralNode",    "", (dockspace_flags & ImGuiDockNodeFlags_PassthruCentralNode) != 0))     dockspace_flags ^= ImGuiDockNodeFlags_PassthruCentralNode;
               if (ImGui::MenuItem("Flag: AutoHideTabBar",         "", (dockspace_flags & ImGuiDockNodeFlags_AutoHideTabBar) != 0))          dockspace_flags ^= ImGuiDockNodeFlags_AutoHideTabBar;
               ImGui::Separator();

               //if (ImGui::MenuItem("Close DockSpace", NULL, false, p_open != NULL)) *p_open = false;
               
               ImGui::EndMenu();
         }
        */

         ImGui::EndMenuBar();
      }
    

      ImGui::End();
   }

	return false;
}