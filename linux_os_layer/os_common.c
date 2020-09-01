#include "os_common.h"

void osa_exit(int status)
{
	exit(status);
}
void osa__exit(int status)
{
	_exit(status);
}

unsigned int osa_sleep_s(unsigned    char seconds)
{
    return sleep(seconds);
}

int osa_sleep_us(osa_useconds_t usec)
{
    return usleep(usec);
}

int osa_thread_create(osa_thread_handle_t* tid, const osa_pthread_attr_t *attr, void *(*thread_function)(void *), void *arg)
{
    return pthread_create(tid, attr, thread_function, arg);
}

int osa_pthread_cancel(osa_thread_handle_t tid)
{
    return pthread_cancel(tid);
}

int osa_pthread_exit(void *ret_value)
{
    pthread_exit(ret_value);
    return 0;
}

int osa_pthread_join(osa_thread_handle_t tid, void **value)
{
    return pthread_join(tid, value);
}

int osa_pthread_detach(osa_thread_handle_t tid)
{
    return pthread_detach(tid);
}



int osa_pthread_mutex_init(osa_pthread_mutex_t *mutex, const osa_pthread_mutexattr_t *attr)
{
	return pthread_mutex_init(mutex, attr);
}

int osa_pthread_mutex_destroy(osa_pthread_mutex_t *mutex)
{
	return pthread_mutex_destroy(mutex);
}

int osa_pthread_mutex_lock(osa_pthread_mutex_t *mutex)
{
	return pthread_mutex_lock(mutex);
}

int osa_pthread_mutex_trylock(osa_pthread_mutex_t *mutex)
{
	return pthread_mutex_trylock(mutex);
}

int osa_pthread_mutex_unlock(osa_pthread_mutex_t *mutex)
{
	return pthread_mutex_unlock(mutex);
}


int osa_pthread_cond_init(osa_pthread_cond_t *cond, const osa_pthread_condattr_t *attr)
{
	return pthread_cond_init(cond, attr);
}
int osa_pthread_cond_destroy(osa_pthread_cond_t *cond)
{
	return pthread_cond_destroy(cond);
}
int osa_pthread_cond_wait(osa_pthread_cond_t *cond, osa_pthread_mutex_t *mutex)
{
	return pthread_cond_wait(cond, mutex);
}
int osa_pthread_cond_signal(osa_pthread_cond_t *cond)
{
	return pthread_cond_signal(cond);
}







