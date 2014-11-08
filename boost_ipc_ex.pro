TEMPLATE=subdirs
#SUBDIRS+=pro/doc_map.pro
#SUBDIRS+=pro/comp_doc_anonymous_conditionA.pro
#SUBDIRS+=pro/comp_doc_anonymous_conditionB.pro
#SUBDIRS+=pro/comp_doc_anonymous_mutexA.pro
#SUBDIRS+=pro/comp_doc_anonymous_mutexB.pro
#SUBDIRS+=pro/doc_cont.pro
#SUBDIRS+=pro/doc_file_mapping.pro
#SUBDIRS+=pro/doc_ipc_message.pro
#SUBDIRS+=pro/doc_managed_grow.pro

#with open('somefile.txt', 'a') as the_file:
#     the_file.write('Hello\n')

# [[[cog
#    import cog, glob
#    for pro in glob.glob('pro/*.pro'):
#       cog.outl("SUBDIRS += %s" % pro)
# ]]]
SUBDIRS += pro/comp_doc_anonymous_conditionA.pro
SUBDIRS += pro/comp_doc_anonymous_conditionB.pro
SUBDIRS += pro/comp_doc_anonymous_mutexA.pro
SUBDIRS += pro/comp_doc_anonymous_mutexB.pro
SUBDIRS += pro/comp_doc_anonymous_semaphoreA.pro
SUBDIRS += pro/comp_doc_anonymous_semaphoreB.pro
SUBDIRS += pro/comp_doc_anonymous_upgradable_mutexA.pro
SUBDIRS += pro/comp_doc_anonymous_upgradable_mutexB.pro
SUBDIRS += pro/comp_doc_message_queueA.pro
SUBDIRS += pro/comp_doc_message_queueB.pro
SUBDIRS += pro/doc_adaptive_pool.pro
SUBDIRS += pro/doc_allocator.pro
SUBDIRS += pro/doc_anonymous_shared_memory.pro
SUBDIRS += pro/doc_bufferstream.pro
SUBDIRS += pro/doc_cached_adaptive_pool.pro
SUBDIRS += pro/doc_cached_node_allocator.pro
SUBDIRS += pro/doc_complex_map.pro
SUBDIRS += pro/doc_cont.pro
SUBDIRS += pro/doc_file_mapping.pro
SUBDIRS += pro/doc_intrusive.pro
SUBDIRS += pro/doc_ipc_message.pro
SUBDIRS += pro/doc_managed_aligned_allocation.pro
SUBDIRS += pro/doc_managed_allocation_command.pro
SUBDIRS += pro/doc_managed_construction_info.pro
SUBDIRS += pro/doc_managed_copy_on_write.pro
SUBDIRS += pro/doc_managed_external_buffer.pro
SUBDIRS += pro/doc_managed_grow.pro
SUBDIRS += pro/doc_managed_heap_memory.pro
SUBDIRS += pro/doc_managed_mapped_file.pro
SUBDIRS += pro/doc_managed_multiple_allocation.pro
SUBDIRS += pro/doc_managed_raw_allocation.pro
SUBDIRS += pro/doc_map.pro
SUBDIRS += pro/doc_move_containers.pro
SUBDIRS += pro/doc_multi_index.pro
SUBDIRS += pro/doc_named_alloc.pro
SUBDIRS += pro/doc_named_mutex.pro
SUBDIRS += pro/doc_node_allocator.pro
SUBDIRS += pro/doc_offset_ptr.pro
SUBDIRS += pro/doc_private_adaptive_pool.pro
SUBDIRS += pro/doc_private_node_allocator.pro
SUBDIRS += pro/doc_scoped_ptr.pro
SUBDIRS += pro/doc_shared_memory.pro
SUBDIRS += pro/doc_shared_ptr.pro
SUBDIRS += pro/doc_shared_ptr_explicit.pro
SUBDIRS += pro/doc_spawn_vector.pro
SUBDIRS += pro/doc_unique_ptr.pro
SUBDIRS += pro/doc_unordered_map.pro
SUBDIRS += pro/doc_vectorstream.pro
SUBDIRS += pro/doc_where_allocate.pro
SUBDIRS += pro/doc_windows_shared_memory.pro
SUBDIRS += pro/doc_xsi_shared_memory.pro
# [[[end]]]
