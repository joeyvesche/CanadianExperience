/**
 * @file PictureObserverTest.cpp
 * @author joeyv
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <PictureObserver.h>
#include <Picture.h>

class PictureObserverMock : public PictureObserver
{
public:
    PictureObserverMock() : PictureObserver() {}
    virtual void UpdateObserver() override {mUpdated = true;}
    bool mUpdated = false;


};

TEST(PictureObserverTest, Construct) {
    PictureObserverMock observer;
}

TEST(PictureObserverTest, OneObserver) {
    // Allocate a Picture object
    auto picture = std::make_shared<Picture>();

    // Create a mock object
    PictureObserverMock observer;

    // Set it
    observer.SetPicture(picture);

    picture->UpdateObservers();

    ASSERT_TRUE(observer.mUpdated);
}

TEST(TestPictureObserverGetPicture, Observer) {
        // Allocate Picture object
        std::shared_ptr<Picture> picture = std::make_shared<Picture>();

        // Create a mock object
        PictureObserverMock observer;

        // Set it for the observer:
        observer.SetPicture(picture);

        ASSERT_TRUE(observer.GetPicture() == picture);

        }

TEST(TestPictureObserverTwoObservers, TwoObserver)
        {
        // Allocate Picture object
        std::shared_ptr<Picture> picture = std::make_shared<Picture>();

        // Create a mock object
        PictureObserverMock observer1;
        PictureObserverMock observer2;

        // And set it for the observer:
        observer1.SetPicture(picture);
        observer2.SetPicture(picture);

        picture->UpdateObservers();

        ASSERT_TRUE(observer1.mUpdated);

        ASSERT_TRUE(observer2.mUpdated);
        }

TEST(TestPictureObserverDestroyed, Observer)
        {
        // Allocate a CPicture object
        std::shared_ptr<Picture> picture = std::make_shared<Picture>();

        // Create a mock
        PictureObserverMock observer1;
        // Set it
        observer1.SetPicture(picture);

        PictureObserverMock observer2;
        observer2.SetPicture(picture);

        // After deleting, check that other observer works
        picture->UpdateObservers();

        ASSERT_TRUE(observer1.mUpdated);
        }


