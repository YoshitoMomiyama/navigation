/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 2.1.6.v20140519.
* Used org.franca.core 0.8.11.201401091023.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#include "POIContentManagerDBusStubAdapter.h"
#include <org/genivi/navigation/poiservice/POIContentManager.h>

namespace org {
namespace genivi {
namespace navigation {
namespace poiservice {

std::shared_ptr<CommonAPI::DBus::DBusStubAdapter> createPOIContentManagerDBusStubAdapter(
                   const std::shared_ptr<CommonAPI::DBus::DBusFactory>& factory,
                   const std::string& commonApiAddress,
                   const std::string& interfaceName,
                   const std::string& busName,
                   const std::string& objectPath,
                   const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusProxyConnection,
                   const std::shared_ptr<CommonAPI::StubBase>& stubBase) {
    return std::make_shared<POIContentManagerDBusStubAdapter>(factory, commonApiAddress, interfaceName, busName, objectPath, dbusProxyConnection, stubBase);
}

INITIALIZER(registerPOIContentManagerDBusStubAdapter) {
    CommonAPI::DBus::DBusFactory::registerAdapterFactoryMethod(POIContentManager::getInterfaceId(),
                                                               &createPOIContentManagerDBusStubAdapter);
}



POIContentManagerDBusStubAdapterInternal::~POIContentManagerDBusStubAdapterInternal() {
    deactivateManagedInstances();
    POIContentManagerDBusStubAdapterHelper::deinit();
}

void POIContentManagerDBusStubAdapterInternal::deactivateManagedInstances() {

}

const char* POIContentManagerDBusStubAdapterInternal::getMethodsDBusIntrospectionXmlData() const {
    static const std::string introspectionData =
        "<method name=\"getInterfaceVersion\">\n"
            "<arg name=\"value\" type=\"uu\" direction=\"out\" />"
        "</method>\n"
        /**
         * guidanceStatusChanged = This signal is sent to the clients when one or more
         *  configuration settings changes.
         */
        "<signal name=\"ConfigurationChanged\">\n"
            "<arg name=\"changedSettings\" type=\"aq\" />\n"
        "</signal>\n"
        /**
         * CategoriesRemoved = This signal is emitted when a list of categories and
         *  associated content has been removed from the database.
         */
        "<signal name=\"CategoriesRemoved\">\n"
            "<arg name=\"categories\" type=\"au\" />\n"
        "</signal>\n"
        /**
         * POIAdded = This signal is emitted when a list of POIs and associated content
         *  has been added to the database. It returns the ids.
         */
        "<signal name=\"POIAdded\">\n"
            "<arg name=\"pois\" type=\"au\" />\n"
        "</signal>\n"
        /**
         * POIRemoved = This signal is emitted when a list of POIs and associated content
         *  has been removed from the database.
         */
        "<signal name=\"POIRemoved\">\n"
            "<arg name=\"pois\" type=\"au\" />\n"
        "</signal>\n"
        /**
         * This method returns the API version implemented by the content access module.
         */
        "<method name=\"getVersion\">\n"
            "<arg name=\"version\" type=\"(qqqs)\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * Set the current language set for the search by poi provider module.
               
         *  The language defines the poi and categories name and details language. If the
         *  language is not supported, the default details will be returned in the native
         *  language.
         */
        "<method name=\"setLocale\">\n"
            "<arg name=\"languageCode\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"countryCode\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"scriptCode\" type=\"s\" direction=\"in\" />\n"
        "</method>\n"
        /**
         * Get the current language set for the search by poi provider module.
         */
        "<method name=\"getLocale\">\n"
            "<arg name=\"languageCode\" type=\"s\" direction=\"out\" />\n"
            "<arg name=\"countryCode\" type=\"s\" direction=\"out\" />\n"
            "<arg name=\"scriptCode\" type=\"s\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * Get the supported set of locales for the search by poi provider module.
         */
        "<method name=\"getSupportedLocales\">\n"
            "<arg name=\"localeList\" type=\"a(sss)\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * This method retrieves the list od POI categories available (pre-defined and
         *  custom).
         */
        "<method name=\"getAvailableCategories\">\n"
            "<arg name=\"categories\" type=\"a(usb)\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * Get the root category id. That would be ALL_CATEGORIES.
         */
        "<method name=\"getRootCategory\">\n"
            "<arg name=\"category\" type=\"u\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * Get the children categories id and type (top level) from the a parent unique id.
         */
        "<method name=\"getChildrenCategories\">\n"
            "<arg name=\"category\" type=\"u\" direction=\"in\" />\n"
            "<arg name=\"categories\" type=\"a(ub)\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * Get the parent categories id and type (top level) from the a unique id.
         */
        "<method name=\"getParentCategories\">\n"
            "<arg name=\"category\" type=\"u\" direction=\"in\" />\n"
            "<arg name=\"categories\" type=\"a(ub)\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * Creates a category by name and return an unique id.
         */
        "<method name=\"createCategory\">\n"
            "<arg name=\"category\" type=\"((au(yv)ss(yv))a(usia(is(yv)))a(us))\" direction=\"in\" />\n"
            "<arg name=\"unique_id\" type=\"u\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * Removes a list of categories. Because of required time to remove it from the
         *  database, a signal is emitted when the deletion is done.
         */
        "<method name=\"removeCategories\">\n"
            "<arg name=\"categories\" type=\"au\" direction=\"in\" />\n"
        "</method>\n"
        /**
         * Adds a list of POIs to a category. Because of required time to add it to the
         *  database, a signal is emitted when the update is done, that gives the id of
         *  the elements added
         */
        "<method name=\"addPOIs\">\n"
            "<arg name=\"unique_id\" type=\"u\" direction=\"in\" />\n"
            "<arg name=\"poiList\" type=\"a(s(ddi)a(ui(yv)))\" direction=\"in\" />\n"
        "</method>\n"
        /**
         * Removes a list of POIs to a category. Because of required time to remove it
         *  from the database, a signal is emitted when the update is done.
         */
        "<method name=\"removePOIs\">\n"
            "<arg name=\"ids\" type=\"au\" direction=\"in\" />\n"
        "</method>\n"
        /**
         * This method is sent by the POI service component to inform all the CAM that a
         *  new POI search was started.
                It provides all the relevant search
         *  parameters. Of course the CAM will only be aware of the search if it registers
         *  one of the search categories.
         */
        "<method name=\"poiSearchStarted\">\n"
            "<arg name=\"poiSearchHandle\" type=\"u\" direction=\"in\" />\n"
            "<arg name=\"maxSize\" type=\"q\" direction=\"in\" />\n"
            "<arg name=\"location\" type=\"(ddi)\" direction=\"in\" />\n"
            "<arg name=\"poiCategories\" type=\"a(uu)\" direction=\"in\" />\n"
            "<arg name=\"poiAttributes\" type=\"a(uui(yv)ib)\" direction=\"in\" />\n"
            "<arg name=\"inputString\" type=\"s\" direction=\"in\" />\n"
            "<arg name=\"sortOption\" type=\"q\" direction=\"in\" />\n"
        "</method>\n"
        /**
         * This method cancels the search for the current id.
         */
        "<method name=\"poiSearchCanceled\">\n"
            "<arg name=\"poiSearchHandle\" type=\"u\" direction=\"in\" />\n"
        "</method>\n"
        /**
         * This method provides the poi results list found by the CAM.
                As the POI
         *  unique id is managed by the POI component, the CAM only provides the POI name,
         *  the category and coordinates as well as all the relevant detailed information.
         */
        "<method name=\"resultListRequested\">\n"
            "<arg name=\"camId\" type=\"y\" direction=\"in\" />\n"
            "<arg name=\"poiSearchHandle\" type=\"u\" direction=\"in\" />\n"
            "<arg name=\"attributes\" type=\"au\" direction=\"in\" />\n"
            "<arg name=\"statusValue\" type=\"i\" direction=\"out\" />\n"
            "<arg name=\"resultListSize\" type=\"q\" direction=\"out\" />\n"
            "<arg name=\"resultList\" type=\"a(usu(ddi)qa(ui(yv)))\" direction=\"out\" />\n"
        "</method>\n"
        /**
         * This method retrieves the details associated to one or more POI.
                It
         *  contains the name, the parent categories, the list of attributes, the icons,
         *  ... .
         */
        "<method name=\"poiDetailsRequested\">\n"
            "<arg name=\"source_id\" type=\"au\" direction=\"in\" />\n"
            "<arg name=\"results\" type=\"a((us(ddi))aua(ui(yv)))\" direction=\"out\" />\n"
        "</method>\n"

    ;
    return introspectionData.c_str();
}

CommonAPI::DBus::DBusGetAttributeStubDispatcher<
        POIContentManagerStub,
        CommonAPI::Version
        > POIContentManagerDBusStubAdapterInternal::getPOIContentManagerInterfaceVersionStubDispatcher(&POIContentManagerStub::getInterfaceVersion, "uu");



/**
 * This method returns the API version implemented by the content access module.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<>,
    std::tuple<NavigationTypes::Version>
    > POIContentManagerDBusStubAdapterInternal::getVersionStubDispatcher(&POIContentManagerStub::getVersion, "(qqqs)");
/**
 * Set the current language set for the search by poi provider module.
       
 *  The language defines the poi and categories name and details language. If the
 *  language is not supported, the default details will be returned in the native
 *  language.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<std::string, std::string, std::string>,
    std::tuple<>
    > POIContentManagerDBusStubAdapterInternal::setLocaleStubDispatcher(&POIContentManagerStub::setLocale, "");
/**
 * Get the current language set for the search by poi provider module.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<>,
    std::tuple<std::string, std::string, std::string>
    > POIContentManagerDBusStubAdapterInternal::getLocaleStubDispatcher(&POIContentManagerStub::getLocale, "sss");
/**
 * Get the supported set of locales for the search by poi provider module.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<>,
    std::tuple<std::vector<POIServiceTypes::Locales>>
    > POIContentManagerDBusStubAdapterInternal::getSupportedLocalesStubDispatcher(&POIContentManagerStub::getSupportedLocales, "a(sss)");
/**
 * This method retrieves the list od POI categories available (pre-defined and
 *  custom).
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<>,
    std::tuple<std::vector<POIServiceTypes::CategoryAndName>>
    > POIContentManagerDBusStubAdapterInternal::getAvailableCategoriesStubDispatcher(&POIContentManagerStub::getAvailableCategories, "a(usb)");
/**
 * Get the root category id. That would be ALL_CATEGORIES.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<>,
    std::tuple<POIServiceTypes::CategoryID>
    > POIContentManagerDBusStubAdapterInternal::getRootCategoryStubDispatcher(&POIContentManagerStub::getRootCategory, "u");
/**
 * Get the children categories id and type (top level) from the a parent unique id.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<POIServiceTypes::CategoryID>,
    std::tuple<std::vector<POIServiceTypes::CategoryAndLevel>>
    > POIContentManagerDBusStubAdapterInternal::getChildrenCategoriesStubDispatcher(&POIContentManagerStub::getChildrenCategories, "a(ub)");
/**
 * Get the parent categories id and type (top level) from the a unique id.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<POIServiceTypes::CategoryID>,
    std::tuple<std::vector<POIServiceTypes::CategoryAndLevel>>
    > POIContentManagerDBusStubAdapterInternal::getParentCategoriesStubDispatcher(&POIContentManagerStub::getParentCategories, "a(ub)");
/**
 * Creates a category by name and return an unique id.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<POIServiceTypes::CAMCategory>,
    std::tuple<POIServiceTypes::CategoryID>
    > POIContentManagerDBusStubAdapterInternal::createCategoryStubDispatcher(&POIContentManagerStub::createCategory, "u");
/**
 * Removes a list of categories. Because of required time to remove it from the
 *  database, a signal is emitted when the deletion is done.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<std::vector<POIServiceTypes::CategoryID>>,
    std::tuple<>
    > POIContentManagerDBusStubAdapterInternal::removeCategoriesStubDispatcher(&POIContentManagerStub::removeCategories, "");
/**
 * Adds a list of POIs to a category. Because of required time to add it to the
 *  database, a signal is emitted when the update is done, that gives the id of
 *  the elements added
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<POIServiceTypes::CategoryID, std::vector<POIServiceTypes::PoiAddedDetails>>,
    std::tuple<>
    > POIContentManagerDBusStubAdapterInternal::addPOIsStubDispatcher(&POIContentManagerStub::addPOIs, "");
/**
 * Removes a list of POIs to a category. Because of required time to remove it
 *  from the database, a signal is emitted when the update is done.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<std::vector<POIServiceTypes::POI_ID>>,
    std::tuple<>
    > POIContentManagerDBusStubAdapterInternal::removePOIsStubDispatcher(&POIContentManagerStub::removePOIs, "");
/**
 * This method is sent by the POI service component to inform all the CAM that a
 *  new POI search was started.
        It provides all the relevant search
 *  parameters. Of course the CAM will only be aware of the search if it registers
 *  one of the search categories.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<NavigationTypes::Handle, uint16_t, NavigationTypes::Coordinate3D, std::vector<POIServiceTypes::CategoryAndRadius>, std::vector<POIServiceTypes::AttributeDetails>, std::string, uint16_t>,
    std::tuple<>
    > POIContentManagerDBusStubAdapterInternal::poiSearchStartedStubDispatcher(&POIContentManagerStub::poiSearchStarted, "");
/**
 * This method cancels the search for the current id.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<NavigationTypes::Handle>,
    std::tuple<>
    > POIContentManagerDBusStubAdapterInternal::poiSearchCanceledStubDispatcher(&POIContentManagerStub::poiSearchCanceled, "");
/**
 * This method provides the poi results list found by the CAM.
        As the POI
 *  unique id is managed by the POI component, the CAM only provides the POI name,
 *  the category and coordinates as well as all the relevant detailed information.
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<uint8_t, NavigationTypes::Handle, std::vector<POIServiceTypes::AttributeID>>,
    std::tuple<POIServiceTypes::SearchStatusState, uint16_t, std::vector<POIServiceTypes::PoiCAMDetails>>
    > POIContentManagerDBusStubAdapterInternal::resultListRequestedStubDispatcher(&POIContentManagerStub::resultListRequested, "iqa(usu(ddi)qa(ui(yv)))");
/**
 * This method retrieves the details associated to one or more POI.
        It
 *  contains the name, the parent categories, the list of attributes, the icons,
 *  ... .
 */
CommonAPI::DBus::DBusMethodWithReplyStubDispatcher<
    POIContentManagerStub,
    std::tuple<std::vector<POIServiceTypes::POI_ID>>,
    std::tuple<std::vector<POIServiceTypes::SearchResultDetails>>
    > POIContentManagerDBusStubAdapterInternal::poiDetailsRequestedStubDispatcher(&POIContentManagerStub::poiDetailsRequested, "a((us(ddi))aua(ui(yv)))");



/**
 * guidanceStatusChanged = This signal is sent to the clients when one or more
 *  configuration settings changes.
 */
void POIContentManagerDBusStubAdapterInternal::fireConfigurationChangedEvent(const std::vector<uint16_t>& changedSettings) {
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<std::vector<uint16_t>>>
            ::sendSignal(
                *this,
                "ConfigurationChanged",
                "aq",
                changedSettings
        );
}
/**
 * CategoriesRemoved = This signal is emitted when a list of categories and
 *  associated content has been removed from the database.
 */
void POIContentManagerDBusStubAdapterInternal::fireCategoriesRemovedEvent(const std::vector<POIServiceTypes::CategoryID>& categories) {
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<std::vector<POIServiceTypes::CategoryID>>>
            ::sendSignal(
                *this,
                "CategoriesRemoved",
                "au",
                categories
        );
}
/**
 * POIAdded = This signal is emitted when a list of POIs and associated content
 *  has been added to the database. It returns the ids.
 */
void POIContentManagerDBusStubAdapterInternal::firePOIAddedEvent(const std::vector<POIServiceTypes::POI_ID>& pois) {
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<std::vector<POIServiceTypes::POI_ID>>>
            ::sendSignal(
                *this,
                "POIAdded",
                "au",
                pois
        );
}
/**
 * POIRemoved = This signal is emitted when a list of POIs and associated content
 *  has been removed from the database.
 */
void POIContentManagerDBusStubAdapterInternal::firePOIRemovedEvent(const std::vector<POIServiceTypes::POI_ID>& pois) {
    CommonAPI::DBus::DBusStubSignalHelper<CommonAPI::DBus::DBusSerializableArguments<std::vector<POIServiceTypes::POI_ID>>>
            ::sendSignal(
                *this,
                "POIRemoved",
                "au",
                pois
        );
}


const POIContentManagerDBusStubAdapterHelper::StubDispatcherTable& POIContentManagerDBusStubAdapterInternal::getStubDispatcherTable() {
    return stubDispatcherTable_;
}

const CommonAPI::DBus::StubAttributeTable& POIContentManagerDBusStubAdapterInternal::getStubAttributeTable() {
    return stubAttributeTable_;
}

POIContentManagerDBusStubAdapterInternal::POIContentManagerDBusStubAdapterInternal(
        const std::shared_ptr<CommonAPI::DBus::DBusFactory>& factory,
        const std::string& commonApiAddress,
        const std::string& dbusInterfaceName,
        const std::string& dbusBusName,
        const std::string& dbusObjectPath,
        const std::shared_ptr<CommonAPI::DBus::DBusProxyConnection>& dbusConnection,
        const std::shared_ptr<CommonAPI::StubBase>& stub):
        CommonAPI::DBus::DBusStubAdapter(
                factory,
                commonApiAddress,
                dbusInterfaceName,
                dbusBusName,
                dbusObjectPath,
                dbusConnection,
                false),
        POIContentManagerDBusStubAdapterHelper(
            factory,
            commonApiAddress,
            dbusInterfaceName,
            dbusBusName,
            dbusObjectPath,
            dbusConnection,
            std::dynamic_pointer_cast<POIContentManagerStub>(stub),
            false),
        stubDispatcherTable_({
            /**
             * This method returns the API version implemented by the content access module.
             */
            { { "getVersion", "" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::getVersionStubDispatcher },
            /**
             * Set the current language set for the search by poi provider module.
                   
             *  The language defines the poi and categories name and details language. If the
             *  language is not supported, the default details will be returned in the native
             *  language.
             */
            { { "setLocale", "sss" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::setLocaleStubDispatcher },
            /**
             * Get the current language set for the search by poi provider module.
             */
            { { "getLocale", "" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::getLocaleStubDispatcher },
            /**
             * Get the supported set of locales for the search by poi provider module.
             */
            { { "getSupportedLocales", "" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::getSupportedLocalesStubDispatcher },
            /**
             * This method retrieves the list od POI categories available (pre-defined and
             *  custom).
             */
            { { "getAvailableCategories", "" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::getAvailableCategoriesStubDispatcher },
            /**
             * Get the root category id. That would be ALL_CATEGORIES.
             */
            { { "getRootCategory", "" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::getRootCategoryStubDispatcher },
            /**
             * Get the children categories id and type (top level) from the a parent unique id.
             */
            { { "getChildrenCategories", "u" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::getChildrenCategoriesStubDispatcher },
            /**
             * Get the parent categories id and type (top level) from the a unique id.
             */
            { { "getParentCategories", "u" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::getParentCategoriesStubDispatcher },
            /**
             * Creates a category by name and return an unique id.
             */
            { { "createCategory", "((au(yv)ss(yv))a(usia(is(yv)))a(us))" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::createCategoryStubDispatcher },
            /**
             * Removes a list of categories. Because of required time to remove it from the
             *  database, a signal is emitted when the deletion is done.
             */
            { { "removeCategories", "au" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::removeCategoriesStubDispatcher },
            /**
             * Adds a list of POIs to a category. Because of required time to add it to the
             *  database, a signal is emitted when the update is done, that gives the id of
             *  the elements added
             */
            { { "addPOIs", "ua(s(ddi)a(ui(yv)))" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::addPOIsStubDispatcher },
            /**
             * Removes a list of POIs to a category. Because of required time to remove it
             *  from the database, a signal is emitted when the update is done.
             */
            { { "removePOIs", "au" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::removePOIsStubDispatcher },
            /**
             * This method is sent by the POI service component to inform all the CAM that a
             *  new POI search was started.
                    It provides all the relevant search
             *  parameters. Of course the CAM will only be aware of the search if it registers
             *  one of the search categories.
             */
            { { "poiSearchStarted", "uq(ddi)a(uu)a(uui(yv)ib)sq" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::poiSearchStartedStubDispatcher },
            /**
             * This method cancels the search for the current id.
             */
            { { "poiSearchCanceled", "u" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::poiSearchCanceledStubDispatcher },
            /**
             * This method provides the poi results list found by the CAM.
                    As the POI
             *  unique id is managed by the POI component, the CAM only provides the POI name,
             *  the category and coordinates as well as all the relevant detailed information.
             */
            { { "resultListRequested", "yuau" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::resultListRequestedStubDispatcher },
            /**
             * This method retrieves the details associated to one or more POI.
                    It
             *  contains the name, the parent categories, the list of attributes, the icons,
             *  ... .
             */
            { { "poiDetailsRequested", "au" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::poiDetailsRequestedStubDispatcher }
            }),
        stubAttributeTable_() {

    stubDispatcherTable_.insert({ { "getInterfaceVersion", "" }, &org::genivi::navigation::poiservice::POIContentManagerDBusStubAdapterInternal::getPOIContentManagerInterfaceVersionStubDispatcher });
}

const bool POIContentManagerDBusStubAdapterInternal::hasFreedesktopProperties() {
    return false;
}

} // namespace poiservice
} // namespace navigation
} // namespace genivi
} // namespace org
