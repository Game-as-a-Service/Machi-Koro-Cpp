set(CONTROLLER_HEADERS
    ${CMAKE_SOURCE_DIR}/controllers/init_game_controller.h
    ${CMAKE_SOURCE_DIR}/controllers/create_game_controller.h
    ${CMAKE_SOURCE_DIR}/controllers/clear_game_controller.h
    ${CMAKE_SOURCE_DIR}/controllers/roll_dice_controller.h
)
set(CONTROLLER_SOURCES
    ${CMAKE_SOURCE_DIR}/controllers/create_game_controller.cpp
    ${CMAKE_SOURCE_DIR}/controllers/clear_game_controller.cpp
    ${CMAKE_SOURCE_DIR}/controllers/roll_dice_controller.cpp
    ${CMAKE_SOURCE_DIR}/controllers/init_game_controller.cpp
)
set(PRESENTER_HEADERS
    ${CMAKE_SOURCE_DIR}/presenters/create_game_present.h
    ${CMAKE_SOURCE_DIR}/presenters/clear_game_present.h
    ${CMAKE_SOURCE_DIR}/presenters/presenter.h
    ${CMAKE_SOURCE_DIR}/presenters/roll_dice_present.h
    ${CMAKE_SOURCE_DIR}/presenters/init_game_present.h
)
set(PRESENTER_SOURCES
    ${CMAKE_SOURCE_DIR}/presenters/create_game_present.cpp
    ${CMAKE_SOURCE_DIR}/presenters/init_game_present.cpp
    ${CMAKE_SOURCE_DIR}/presenters/roll_dice_present.cpp
    ${CMAKE_SOURCE_DIR}/presenters/clear_game_present.cpp
)
set(LOGGER_HEADERS
    ${CMAKE_SOURCE_DIR}/loggers/logger_base.h
    ${CMAKE_SOURCE_DIR}/loggers/logger.h
)
set(LOGGER_SOURCES
    ${CMAKE_SOURCE_DIR}/loggers/logger.cpp
)
set(REPO_HEADERS
    ${CMAKE_SOURCE_DIR}/repos/memory_repository.h
    ${CMAKE_SOURCE_DIR}/repos/repository.h
)
set(REPO_SOURCES
    ${CMAKE_SOURCE_DIR}/repos/memory_repository.cpp
)
set(UTIL_HEADERS
    ${CMAKE_SOURCE_DIR}/utils/util_base.h
    ${CMAKE_SOURCE_DIR}/utils/util.h
)
set(UTIL_SOURCES
    ${CMAKE_SOURCE_DIR}/utils/util.cpp
)
set(USECASE_HEADERS
    ${CMAKE_SOURCE_DIR}/usecases/create_game.h
    ${CMAKE_SOURCE_DIR}/usecases/clear_game.h
    ${CMAKE_SOURCE_DIR}/usecases/init_game.h
    ${CMAKE_SOURCE_DIR}/usecases/roll_dice.h
)
set(USECASE_SOURCES
    ${CMAKE_SOURCE_DIR}/usecases/create_game.cpp
    ${CMAKE_SOURCE_DIR}/usecases/init_game.cpp
    ${CMAKE_SOURCE_DIR}/usecases/clear_game.cpp
    ${CMAKE_SOURCE_DIR}/usecases/roll_dice.cpp
)
set(MODEL_HEADERS
    ${CMAKE_SOURCE_DIR}/models/dice.h
    ${CMAKE_SOURCE_DIR}/models/bank.h
    ${CMAKE_SOURCE_DIR}/models/machikoro_game.h
    ${CMAKE_SOURCE_DIR}/models/architecture_market.h
    ${CMAKE_SOURCE_DIR}/models/dice_base.h
    ${CMAKE_SOURCE_DIR}/models/player.h
    ${CMAKE_SOURCE_DIR}/models/tests/mock_dice.h
    ${CMAKE_SOURCE_DIR}/models/events/roll_dice_event.h
    ${CMAKE_SOURCE_DIR}/models/events/event_player.h
    ${CMAKE_SOURCE_DIR}/models/events/init_game_event.h
    ${CMAKE_SOURCE_DIR}/models/events/create_game_event.h
    ${CMAKE_SOURCE_DIR}/models/events/clear_game_event.h
    ${CMAKE_SOURCE_DIR}/models/events/event.h
    ${CMAKE_SOURCE_DIR}/models/hand.h
    ${CMAKE_SOURCE_DIR}/models/cards/radio_tower.h
    ${CMAKE_SOURCE_DIR}/models/cards/stadium.h
    ${CMAKE_SOURCE_DIR}/models/cards/card.h
    ${CMAKE_SOURCE_DIR}/models/cards/ranch.h
    ${CMAKE_SOURCE_DIR}/models/cards/amusement_park.h
    ${CMAKE_SOURCE_DIR}/models/cards/mine.h
    ${CMAKE_SOURCE_DIR}/models/cards/tv_station.h
    ${CMAKE_SOURCE_DIR}/models/cards/wheat_field.h
    ${CMAKE_SOURCE_DIR}/models/cards/cafe.h
    ${CMAKE_SOURCE_DIR}/models/cards/family_restaurant.h
    ${CMAKE_SOURCE_DIR}/models/cards/apple_orchard.h
    ${CMAKE_SOURCE_DIR}/models/cards/business_center.h
    ${CMAKE_SOURCE_DIR}/models/cards/landmark.h
    ${CMAKE_SOURCE_DIR}/models/cards/building.h
    ${CMAKE_SOURCE_DIR}/models/cards/cheese_factory.h
    ${CMAKE_SOURCE_DIR}/models/cards/bakery.h
    ${CMAKE_SOURCE_DIR}/models/cards/fruit_and_vegetable_market.h
    ${CMAKE_SOURCE_DIR}/models/cards/shopping_mall.h
    ${CMAKE_SOURCE_DIR}/models/cards/convenient_store.h
    ${CMAKE_SOURCE_DIR}/models/cards/furniture_factory.h
    ${CMAKE_SOURCE_DIR}/models/cards/forest.h
    ${CMAKE_SOURCE_DIR}/models/cards/train_station.h
)
set(MODEL_SOURCES
    ${CMAKE_SOURCE_DIR}/models/dice.cpp
    ${CMAKE_SOURCE_DIR}/models/machikoro_game.cpp
    ${CMAKE_SOURCE_DIR}/models/bank.cpp
    ${CMAKE_SOURCE_DIR}/models/player.cpp
    ${CMAKE_SOURCE_DIR}/models/hand.cpp
    ${CMAKE_SOURCE_DIR}/models/events/roll_dice_event.cpp
    ${CMAKE_SOURCE_DIR}/models/events/init_game_event.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/convenient_store.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/landmark.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/forest.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/radio_tower.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/bakery.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/shopping_mall.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/mine.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/cheese_factory.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/family_restaurant.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/wheat_field.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/amusement_park.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/tv_station.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/cafe.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/train_station.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/business_center.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/apple_orchard.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/ranch.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/building.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/furniture_factory.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/card.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/fruit_and_vegetable_market.cpp
    ${CMAKE_SOURCE_DIR}/models/cards/stadium.cpp
    ${CMAKE_SOURCE_DIR}/models/architecture_market.cpp
)
set(E2E_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/e2e_test/e2e_rolldice.cpp
    ${CMAKE_SOURCE_DIR}/tests/e2e_test/e2e_main.cpp
    ${CMAKE_SOURCE_DIR}/tests/e2e_test/test_def.h
    ${CMAKE_SOURCE_DIR}/tests/e2e_test/e2e_init_game.cpp
    ${CMAKE_SOURCE_DIR}/tests/e2e_test/e2e_create_game.cpp
)
set(UNIT_SOURCES
    ${CMAKE_SOURCE_DIR}/tests/unittest/unit_operate_effect.cpp
    ${CMAKE_SOURCE_DIR}/tests/unittest/unit_game.cpp
)
