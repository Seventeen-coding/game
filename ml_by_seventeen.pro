TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/mielong2014050302.c \
    main.c \
    window/main_window.c \
    window/hero_window.c \
    data/hero_data.c \
    story/story.c \
    window/sl_window.c \
    data/sl_data.c \
    window/city_window.c \
    map/city_map.c \
    map/main_map.c \
    map/map.c \
    map/new_game_map.c \
    map/hero_map.c \
    map/help_map.c \
    window/help_window.c \
    map/sl_map.c \
    window/item_window.c \
    window/shop_window.c \
    map/shop_map.c \
    window/window.c \
    map/world_map.c \
    window/bar_window.c \
    map/bar_map.c \
    data/place_data.c \
    data/skill_data.c \
    data/enemy_data.c \
    list/list.c \
    init_game.c \
    window/fight_window.c \
    map/fight_map.c \
    data/fight_data.c \
    data/item_data.c \
    game/game.c \
    game/game_key.c \
    game/game_story.c \
    game/game_test.c \
    game/game_node.c \
    game/game_map.c \
    map/game_map_init.c \
    node/game_node_init.c \
    list/game_story_list_init.c \
    story/welcome/welcome_story.c \
    map/welcome/welcome_map.c \
    map/welcome/welcome_movie_map.c \
    node/welcome/welcome_node.c \
    game/game_window.c \
    game/game_window_type.c \
    window/basic/select_list.c \
    window/basic/w_text.c \
    story/game_story_init.c


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    main.h \
    window/include/main_window.h \
    window/include/hero_window.h \
    data/include/hero_data.h \
    story/include/story.h \
    window/include/sl_window.h \
    data/include/sl_data.h \
    data/include/base_data.h \
    window/include/city_window.h \
    map/include/city_map.h \
    map/include/main_map.h \
    map/include/map.h \
    map/include/new_game_map.h \
    map/include/hero_map.h \
    map/include/help_map.h \
    window/include/help_window.h \
    map/include/sl_map.h \
    data/include/item_data.h \
    window/include/item_window.h \
    window/include/shop_window.h \
    map/include/shop_map.h \
    window/include/window.h \
    window/include/world_window.h \
    map/include/world_map.h \
    window/include/bar_window.h \
    map/include/bar_map.h \
    data/include/place_data.h \
    data/include/enemy_data.h \
    data/include/skill_data.h \
    data/include/data.h \
    list/list.h \
    window/include/fight_window.h \
    map/include/fight_map.h \
    data/include/fight_data.h \
    game/game.h \
    game/game_map.h \
    game/game_key.h \
    game/game_node.h \
    game/game_story.h \
    game/game_debug.h \
    game/game_test.h \
    game/game_test_module.h \
    test/game_test_demo_map.h \
    game/game_goble.h \
    node/welcome/map/welcome_map.h \
    node/welcome/welcome_private.h \
    node/welcome/welcome.h \
    node/welcome/map/welcome_movie_map.h \
    map/welcome/map/welcome_map.h \
    map/welcome/map/welcome_movie_map.h \
    map/game_map_config.h \
    map/game_map_init.h \
    story/include/game_story_config.h \
    story/include/game_story_init.h \
    node/game_node_config.h \
    node/game_node_init.h \
    list/game_story_list_init.h \
    list/game_story_list_config.h \
    story/welcome/welcome_story.h \
    story/game_story_config.h \
    story/game_story_init.h \
    game/game_list.h \
    node/welcome/welcome_node.h \
    map/welcome/welcome_map.h \
    map/welcome/welcome_movie_map.h \
    game/game_window.h \
    window/welcome/welcome_window.h \
    game/game_window_type.h \
    window/basic/select_list.h \
    window/basic/w_list.h \
    window/basic/w_text.h
