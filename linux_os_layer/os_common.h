#ifndef __OS_COMMON_H__
#define __OS_COMMON_H__

#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define osa_printf printf


typedef  useconds_t           osa_useconds_t;
typedef  pthread_t            osa_thread_handle_t;
typedef  pthread_attr_t       osa_pthread_attr_t;
typedef  pthread_mutex_t      osa_pthread_mutex_t;
typedef  pthread_mutexattr_t  osa_pthread_mutexattr_t;
typedef  pthread_cond_t       osa_pthread_cond_t;
typedef  pthread_condattr_t   osa_pthread_condattr_t;


void osa_exit(int status);
void osa__exit(int status);

unsigned int osa_sleep_s(unsigned char seconds);
int osa_sleep_us(osa_useconds_t usec);

int osa_thread_create(osa_thread_handle_t* tid, const osa_pthread_attr_t *attr, void *(*thread_function)(void *), void *arg);
int osa_pthread_cancel(osa_thread_handle_t tid);
int osa_pthread_exit(void *ret_value);
int osa_pthread_join(osa_thread_handle_t tid, void **value);
int osa_pthread_detach(osa_thread_handle_t tid);

int osa_pthread_mutex_init(osa_pthread_mutex_t *mutex, const osa_pthread_mutexattr_t *attr);
int osa_pthread_mutex_destroy(osa_pthread_mutex_t *mutex);
int osa_pthread_mutex_lock(osa_pthread_mutex_t *mutex);
int osa_pthread_mutex_trylock(osa_pthread_mutex_t *mutex);
int osa_pthread_mutex_unlock(osa_pthread_mutex_t *mutex);

int osa_pthread_cond_init(osa_pthread_cond_t *cond, const osa_pthread_condattr_t *attr);
int osa_pthread_cond_destroy(osa_pthread_cond_t *cond);
int osa_pthread_cond_wait(osa_pthread_cond_t *cond, osa_pthread_mutex_t *mutex);
int osa_pthread_cond_signal(osa_pthread_cond_t *cond);


#endif // __osa_COMMON_H__
