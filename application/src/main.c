#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

int main(void) {
    printk("Hello World from %s!\n", CONFIG_BOARD);
    LOG_DBG("Hello World from %s!", CONFIG_BOARD);
    LOG_INF("Hello World from %s!", CONFIG_BOARD);
    LOG_WRN("Hello World from %s!", CONFIG_BOARD);
    LOG_ERR("Hello World from %s!", CONFIG_BOARD);
    return 0;
}