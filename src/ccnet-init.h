#ifndef WINGUFILE_CLIENT_CCNET_INIT_H
#define WINGUFILE_CLIENT_CCNET_INIT_H

int  create_ccnet_config(const char *ccnet_dir);

enum {
    ERR_PERMISSION = 1,
    ERR_CONF_FILE,
    ERR_WINGUFILE_CONF,
    ERR_MAX_NUM,
};

#endif
