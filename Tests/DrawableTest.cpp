/**
 * @file DrawableTest.cpp
 * @author joeyv
 */

#include <pch.h>
#include <Drawable.h>
#include <Picture.h>
#include <memory>
#include "gtest/gtest.h"
#include <wx/filefn.h>

class DrawableMock : public Drawable{
public:
    DrawableMock(const std::wstring &name) : Drawable(name) {}

    virtual void Draw(std::shared_ptr<wxGraphicsContext> graphics) override {}
    virtual bool HitTest(wxPoint pos) override { return false; }

};

TEST(TestDrawableConstructor, Drawable)
{
    DrawableMock drawn(L"test");
    ASSERT_EQ(std::wstring(L"test"), drawn.GetName());
}

TEST(TestDrawablePositionGetterSetter, Drawable)
{
    DrawableMock drawn(L"test");
    // test default position
    ASSERT_EQ(0, drawn.GetPosition().x);
    ASSERT_EQ(0, drawn.GetPosition().y);

    // test getter and setter
    drawn.SetPosition(wxPoint(54,52));
    ASSERT_EQ(54, drawn.GetPosition().x);
    ASSERT_EQ(52, drawn.GetPosition().y);

}

TEST(TestDrawableRotationGetterSetter, Drawable)
{
    DrawableMock drawn(L"test");
    // test default position
    ASSERT_NEAR(0, drawn.GetRotation(), 0.00001);

    // test getter and setter
    drawn.SetRotation(.333);
    ASSERT_EQ(.333, drawn.GetRotation());
    double b = acos(cos(drawn.GetRotation()));
    ASSERT_NEAR(drawn.GetRotation(), b, 0.000000001);

}

TEST(DrawableTest, Association)
{
    DrawableMock body(L"Body");
    auto arm = std::make_shared<DrawableMock>(L"Arm");
    auto leg = std::make_shared<DrawableMock>(L"Leg");

    ASSERT_EQ(nullptr, arm->GetParent());
    ASSERT_EQ(nullptr, leg->GetParent());

    body.AddChild(arm);
    body.AddChild(leg);

    ASSERT_EQ(&body, arm->GetParent());
    ASSERT_EQ(&body, leg->GetParent());
}