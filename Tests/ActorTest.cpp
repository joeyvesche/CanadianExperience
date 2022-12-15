/**
 * @file ActorTest.cpp
 * @author joeyv
 */

#include <pch.h>

#include <Actor.h>
#include <Picture.h>
#include <memory>
#include "gtest/gtest.h"
#include <wx/filefn.h>

using namespace std;

TEST(ActorTest, Constructor)
{
    Actor actor(L"Harold");
    ASSERT_EQ(std::wstring(L"Harold"), actor.GetName());
    ASSERT_NE(std::wstring(L"Kumar"), actor.GetName());
}

TEST(TestActorEnabledGetterSetter, Actor)
{
    Actor actor(L"Harold");
    // test default value and getter
    ASSERT_TRUE(actor.IsEnabled() == true);
    // Test setter and getter
    actor.SetEnabled(false);
    ASSERT_TRUE(actor.IsEnabled() == false);
}

TEST(TestActorClickableGetterSetter, Actor)
{
    Actor actor(L"Harold");
    // test default value and getter
    ASSERT_TRUE(actor.IsClickable() == true);
    // Test setter and getter
    actor.SetClickable(false);
    ASSERT_TRUE(actor.IsClickable() == false);
}

TEST(TestActorPositionGetterSetter, Actor)
{
    Actor actor(L"Harold");
    // default value test
    ASSERT_EQ(0, actor.GetPosition().x);
    ASSERT_EQ(0, actor.GetPosition().y);

    // test getter and setter
    actor.SetPosition(wxPoint(60, 90));
    ASSERT_EQ(60, actor.GetPosition().x);
    ASSERT_EQ(90, actor.GetPosition().y);
}