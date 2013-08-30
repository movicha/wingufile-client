#include <glib.h>
#include <glib-object.h>

#include <vector>

extern "C" {

#include <searpc.h>    
#include <wingufile/wingufile.h>
#include <wingufile/wingufile-object.h>

}


#include "local-repo.h"

#include "requests.h"

/**
 * ListLocalReposRequest
 */
ListLocalReposRequest::ListLocalReposRequest()
{
}

void ListLocalReposRequest::send()
{
    searpc_client_async_call__objlist (
        getSeafRpcClient(),
        "wingufile_get_repo_list", (AsyncCallback)callbackWrapper,
        WINGUFILE_TYPE_REPO, this, 0);
}

void ListLocalReposRequest::onRpcFinished(void *data)
{
    std::vector<LocalRepo> repos;
    GList *obj_list = (GList *)data;
    for (GList *ptr = obj_list; ptr; ptr = ptr->next) {
        GObject *obj = static_cast<GObject*>(ptr->data);
        repos.push_back(LocalRepo::fromGObject((GObject*)obj));
    }

    emit success(repos);
}


/**
 * SetAutoSyncRequest
 **/
SetAutoSyncRequest::SetAutoSyncRequest(bool auto_sync)
    : auto_sync_(auto_sync)
{
}

void SetAutoSyncRequest::send()
{
    if (auto_sync_) {
        wingufile_enable_auto_sync_async (getSeafRpcClient(),
                                        (AsyncCallback)callbackWrapper,
                                        this);
    } else {
        wingufile_disable_auto_sync_async (getSeafRpcClient(),
                                         (AsyncCallback)callbackWrapper,
                                         this);
    }
}

void SetAutoSyncRequest::onRpcFinished(void *result)
{
    emit success(auto_sync_);
}
