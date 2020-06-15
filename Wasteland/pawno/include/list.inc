/*
	Linked lists in PAWN made by BigETI © 2013
*/
#if defined _LIST_INCLUDED_
	#endinput
#endif
#define _LIST_INCLUDED_
#include <memory>
#if defined MEM_NULL_EX
	#define LIST_NULL_	MEM_EX::NULL
#else
	#define LIST_NULL_	NULL
#endif
#define LIST_init%1<%0>					List:%0[LIST_E_base]
#define LIST_begin%1(%0)				(ListIt:%0[LIST_base_begin])
#define LIST_end%1(%0)					(ListIt:%0[LIST_base_end])
#define LIST_exist%1(%0)				(!!LIST_find(%0))
#define LIST_arr_exist%1(%0)			(!!LIST_find_arr(%0))
#define LIST_IT_data_ptr%1(%0)			(MEM_EX::get_ptr(Pointer:(%0)->LIST_IT_data_data_offset))
#if defined SECURE_MEMORY_PLUGIN
	#define LIST_IT_data_val%2(%0,%1)	(MEM_EX::get_val(Pointer:(%0)->(LIST_IT_data_data_offset+(%1))))
#else
	#define LIST_IT_data_val%2(%0,%1)	(MEM_EX::get_val(LIST_IT_data_ptr(%0)->(%1)))
#endif
#define LIST_IT_next%1(%0)				ListIt:MEM_EX::get_val(Pointer:(%0)->LIST_IT_data_next)
#define LIST_IT_previous%1(%0)			ListIt:MEM_EX::get_val(Pointer:(%0)->LIST_IT_data_previous)
#define LIST_IT_data_size%1(%0)			MEM_EX::get_val(Pointer:(%0)->LIST_IT_data_data_size)
#define LIST_foreach%2<%0>%3(%1)		for(new ListIt:%0 = ListIt:%1[LIST_base_begin]; _:%0 != LIST_NULL_; %0 = ListIt:MEM_EX::get_val(Pointer:(%0)->LIST_IT_data_next))
#define LIST_foreach_rev%2<%0>%3(%1)	for(new ListIt:%0 = ListIt:%1[LIST_base_end]; _:%0 != LIST_NULL_; %0 = ListIt:MEM_EX::get_val(Pointer:(%0)->LIST_IT_data_previous))
#define foreach_list%2(%0:%1)	for(new ListIt:_%0_=ListIt:%1[LIST_base_end],%0;_:_%0_!=0;_%0_=ListIt:MEM_EX::get_val(Pointer:(_%0_)->LIST_IT_data_previous))if((%0=MEM_EX::get_val(LIST_IT_data_ptr(_%0_)->0))>=0)
MEM::struct LIST_E_base
{
	LIST_base_begin,
	LIST_base_end
}
MEM::struct LIST_IT_data
{
	LIST_IT_data_next,
	LIST_IT_data_previous,
	LIST_IT_data_data_size,
	LIST_IT_data_data_offset
}
static const LIST_file_header[] = {0xD, 0xA, 0x14, 0x15, 0x0, 0x7, 0xA, 0xD, 0x6};
stock ListIt:LIST_push_back(List:list[], value)
{
	new Pointer:next_LIST_ptr = MEM::calloc(LIST_IT_data_data_offset+1);
	if(next_LIST_ptr)
	{
		if(list[LIST_base_end])
		{
			MEM::set_val(Pointer:list[LIST_base_end], LIST_IT_data_next, _:next_LIST_ptr);
			MEM::set_val(next_LIST_ptr, LIST_IT_data_previous, list[LIST_base_end]);
		}
		else if(list[LIST_base_begin] == LIST_NULL_) list[LIST_base_begin] = _:next_LIST_ptr;
		list[LIST_base_end] = _:next_LIST_ptr;
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_size, 1);
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_offset, value);
		return LIST_end(list);
	}
	return ListIt:LIST_NULL_;
}
stock ListIt:LIST_push_back_arr(List:list[], arr[], arr_size = sizeof arr)
{
	if(arr_size < 1) return ListIt:LIST_NULL_;
	new Pointer:next_LIST_ptr = MEM::calloc(arr_size+LIST_IT_data_data_offset);
	if(next_LIST_ptr)
	{
		if(list[LIST_base_end])
		{
			MEM::set_val(Pointer:list[LIST_base_end], LIST_IT_data_next, _:next_LIST_ptr);
			MEM::set_val(next_LIST_ptr, LIST_IT_data_previous, list[LIST_base_end]);
		}
		else if(list[LIST_base_begin] == LIST_NULL_) list[LIST_base_begin] = _:next_LIST_ptr;
		list[LIST_base_end] = _:next_LIST_ptr;
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_size, arr_size);
		MEM::set_arr(next_LIST_ptr, LIST_IT_data_data_offset, arr, arr_size);
		return LIST_end(list);
	}
	return ListIt:LIST_NULL_;
}
stock ListIt:LIST_pop_back(List:list[])
{
	if(list[LIST_base_begin] == LIST_NULL_) return ListIt:LIST_NULL_;
	new last_node = MEM_EX::get_val(Pointer:list[LIST_base_end]->LIST_IT_data_previous);
	if(last_node)
	{
		MEM::set_val(Pointer:last_node, LIST_IT_data_next, LIST_NULL_);
		MEM::free(Pointer:list[LIST_base_end]);
		return ListIt:(list[LIST_base_end] = last_node);
	}
	list[LIST_base_begin] = LIST_NULL_;
	list[LIST_base_end] = LIST_NULL_;
	return ListIt:LIST_NULL_;
}
stock ListIt:LIST_push_front(List:list[], value)
{
	new Pointer:next_LIST_ptr = MEM::calloc(LIST_IT_data_data_offset+1);
	if(next_LIST_ptr)
	{
		if(list[LIST_base_begin])
		{
			MEM::set_val(Pointer:list[LIST_base_begin], LIST_IT_data_previous, _:next_LIST_ptr);
			MEM::set_val(next_LIST_ptr, LIST_IT_data_next, list[LIST_base_begin]);
		}
		else list[LIST_base_end] = _:next_LIST_ptr;
		list[LIST_base_begin] = _:next_LIST_ptr;
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_size, 1);
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_offset, value);
		return LIST_begin(list);
	}
	return ListIt:LIST_NULL_;
}
stock ListIt:LIST_push_front_arr(List:list[], arr[], arr_size = sizeof arr)
{
	new Pointer:next_LIST_ptr = MEM::calloc(LIST_IT_data_data_offset+arr_size);
	if(next_LIST_ptr)
	{
		if(list[LIST_base_begin])
		{
			MEM::set_val(Pointer:list[LIST_base_begin], LIST_IT_data_previous, _:next_LIST_ptr);
			MEM::set_val(next_LIST_ptr, LIST_IT_data_next, list[LIST_base_begin]);
		}
		else list[LIST_base_end] = _:next_LIST_ptr;
		list[LIST_base_begin] = _:next_LIST_ptr;
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_size, arr_size);
		MEM::set_arr(next_LIST_ptr, LIST_IT_data_data_offset, arr, arr_size);
		return LIST_begin(list);
	}
	return ListIt:LIST_NULL_;
}
stock ListIt:LIST_pop_front(List:list[])
{
	if(!list[LIST_base_begin]) return ListIt:LIST_NULL_;
	new Pointer:free_node = Pointer:list[LIST_base_begin];
	if((list[LIST_base_begin] = MEM_EX::get_val(Pointer:list[LIST_base_begin]->LIST_IT_data_next))) MEM::set_val(Pointer:list[LIST_base_begin], LIST_IT_data_previous, LIST_NULL_);
	else list[LIST_base_end] = LIST_NULL_;
	MEM::free(free_node);
	return LIST_begin(list);
}
stock ListIt:LIST_insert(List:list[], ListIt:node, value)
{
	if(_:node == LIST_NULL_) return ListIt:LIST_NULL_;
	new Pointer:next_LIST_ptr = MEM::calloc(LIST_IT_data_data_offset+1);
	if(next_LIST_ptr)
	{
		if(_:node == list[LIST_base_begin]) list[LIST_base_begin] = _:next_LIST_ptr;
		else
		{
			MEM::set_val(next_LIST_ptr, LIST_IT_data_previous, MEM_EX::get_val(Pointer:node->LIST_IT_data_previous));
			MEM::set_val(Pointer:MEM_EX::get_val(Pointer:node->LIST_IT_data_previous), LIST_IT_data_next, _:next_LIST_ptr);
		}
		MEM::set_val(Pointer:node, LIST_IT_data_previous, _:next_LIST_ptr);
		MEM::set_val(next_LIST_ptr, LIST_IT_data_next, _:node);
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_size, 1);
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_offset, value);
		return ListIt:next_LIST_ptr;
	}
	return ListIt:LIST_NULL_;
}
stock ListIt:LIST_insert_arr(List:list[], ListIt:node, arr[], arr_size = sizeof arr)
{
	if(_:node == LIST_NULL_) return ListIt:LIST_NULL_;
	new Pointer:next_LIST_ptr = MEM::calloc(LIST_IT_data_data_offset+arr_size);
	if(next_LIST_ptr)
	{
		if(_:node == list[LIST_base_begin]) list[LIST_base_begin] = _:next_LIST_ptr;
		else
		{
			MEM::set_val(next_LIST_ptr, LIST_IT_data_previous, MEM_EX::get_val(Pointer:node->LIST_IT_data_previous));
			MEM::set_val(Pointer:MEM_EX::get_val(Pointer:node->LIST_IT_data_previous), LIST_IT_data_next, _:next_LIST_ptr);
		}
		MEM::set_val(Pointer:node, LIST_IT_data_previous, _:next_LIST_ptr);
		MEM::set_val(next_LIST_ptr, LIST_IT_data_next, _:node);
		MEM::set_val(next_LIST_ptr, LIST_IT_data_data_size, arr_size);
		MEM::set_arr(next_LIST_ptr, LIST_IT_data_data_offset, arr, arr_size);
		return ListIt:next_LIST_ptr;
	}
	return ListIt:LIST_NULL_;
}
stock ListIt:LIST_erase(List:list[], ListIt:node)
{
	if(_:node == LIST_NULL_) return ListIt:LIST_NULL_;
	new prev_addr = MEM_EX::get_val(Pointer:node->LIST_IT_data_previous), next_addr = MEM_EX::get_val(Pointer:node->LIST_IT_data_next);
	if(list[LIST_base_begin] == _:node)
	{
		if(list[LIST_base_end] == _:node)
		{
			list[LIST_base_begin] = LIST_NULL_;
			list[LIST_base_end] = LIST_NULL_;
			MEM::free(Pointer:node);
			return ListIt:LIST_NULL_;
		}
		MEM::set_val(Pointer:next_addr, LIST_IT_data_previous, LIST_NULL_);
		MEM::free(Pointer:node);
		return ListIt:(list[LIST_base_begin] = next_addr);
	}
	if(list[LIST_base_end] == _:node)
	{
		MEM::set_val(Pointer:prev_addr, LIST_IT_data_next, LIST_NULL_);
		list[LIST_base_end] = prev_addr;
		MEM::free(Pointer:node);
		return ListIt:LIST_NULL_;
	}
	MEM::set_val(Pointer:prev_addr, LIST_IT_data_next, next_addr);
	MEM::set_val(Pointer:next_addr, LIST_IT_data_previous, prev_addr);
	MEM::free(Pointer:node);
	return ListIt:next_addr;
}
stock ListIt:LIST_find(List:list[], value, index = 0, bool:reverse = false, jump = 0)
{
	if(index < 0) return ListIt:LIST_NULL_;
	new do_jump = jump;
	if(reverse)
	{
		for(new Pointer:find_node = Pointer:list[LIST_base_end]; _:find_node != LIST_NULL_; find_node = Pointer:MEM_EX::get_val(find_node->LIST_IT_data_previous))
		{
			if(LIST_IT_data_size(find_node) <= index) continue;
			if(MEM_EX::get_val(find_node->(LIST_IT_data_data_offset+index)) != value) continue;
			if(do_jump-- > 0) continue;
			return ListIt:find_node;
		}
	}
	else
	{
		for(new Pointer:find_node = Pointer:list[LIST_base_begin]; _:find_node != LIST_NULL_; find_node = Pointer:MEM_EX::get_val(find_node->LIST_IT_data_next))
		{
			if(LIST_IT_data_size(find_node) <= index) continue;
			if(MEM_EX::get_val(find_node->(LIST_IT_data_data_offset+index)) != value) continue;
			if(do_jump-- > 0) continue;
			return ListIt:find_node;
		}
	}
	return ListIt:LIST_NULL_;
}
stock ListIt:LIST_find_arr(List:list[], arr[], arr_size = sizeof arr, index = 0, bool:reverse = false, jump = 0)
{
	if(arr_size-index <= 0) return ListIt:LIST_NULL_;
	new arr_i, bool:do_continue = false, do_jump = jump;
	if(reverse)
	{
		for(new Pointer:find_node = Pointer:list[LIST_base_end]; _:find_node != LIST_NULL_; find_node = Pointer:MEM_EX::get_val(find_node->LIST_IT_data_previous))
		{
			for(arr_i = 0; arr_i < arr_size; arr_i++)
			{
				if(LIST_IT_data_size(find_node) <= (index+arr_i))
				{
					do_continue = true;
					break;
				}
				if(MEM_EX::get_val(find_node->(LIST_IT_data_data_offset+(index+arr_i))) != arr[arr_i])
				{
					do_continue = true;
					break;
				}
			}
			if(do_continue)
			{
				do_continue = false;
				continue;
			}
			if(do_jump-- > 0) continue;
			return ListIt:find_node;
		}
	}
	else
	{
		for(new Pointer:find_node = Pointer:list[LIST_base_begin]; _:find_node != LIST_NULL_; find_node = Pointer:MEM_EX::get_val(find_node->LIST_IT_data_next))
		{
			for(arr_i = 0; arr_i < arr_size; arr_i++)
			{
				if(LIST_IT_data_size(find_node) <= (index+arr_i))
				{
					do_continue = true;
					break;
				}
				if(MEM_EX::get_val(find_node->(LIST_IT_data_data_offset+(index+arr_i))) != arr[arr_i])
				{
					do_continue = true;
					break;
				}
			}
			if(do_continue)
			{
				do_continue = false;
				continue;
			}
			if(do_jump-- > 0) continue;
			return ListIt:find_node;
		}
	}
	return ListIt:LIST_NULL_;
}
stock LIST_count_found(List:list[], value, index = 0)
{
	if(index < 0) return 0;
	new count = 0;
	for(new Pointer:find_node = Pointer:list[LIST_base_begin]; _:find_node != LIST_NULL_; find_node = Pointer:MEM_EX::get_val(find_node->LIST_IT_data_next))
	{
		if(LIST_IT_data_size(find_node) <= index) continue;
		if(MEM_EX::get_val(find_node->(LIST_IT_data_data_offset+index)) != value) continue;
		count++;
	}
	return count;
}
stock LIST_count_found_arr(List:list[], arr[], arr_size = sizeof arr, index = 0)
{
	if(arr_size-index <= 0) return 0;
	new count = 0, arr_i, bool:do_continue = false;
	for(new Pointer:find_node = Pointer:list[LIST_base_begin]; _:find_node != LIST_NULL_; find_node = Pointer:MEM_EX::get_val(find_node->LIST_IT_data_next))
	{
		for(arr_i = 0; arr_i < arr_size; arr_i++)
		{
			if(LIST_IT_data_size(find_node) <= (index+arr_i))
			{
				do_continue = true;
				break;
			}
			if(MEM_EX::get_val(find_node->(LIST_IT_data_data_offset+(index+arr_i))) != arr[arr_i])
			{
				do_continue = true;
				break;
			}
		}
		if(do_continue)
		{
			do_continue = false;
			continue;
		}
		count++;
	}
	return count;
}
stock LIST_sort(List:list[], bool:descending = false)
{
	new bool:allow_repeat = true, Pointer:sort_it, Pointer:next_node, size_1, size_2, cmp_i, Pointer:temp_node, data_1, data_2;
	if(descending)
	{
		while(allow_repeat)
		{
			allow_repeat = false;
			for(sort_it = Pointer:list[LIST_base_begin]; (next_node = Pointer:MEM_EX::get_val(sort_it->LIST_IT_data_next)); sort_it = Pointer:MEM_EX::get_val(sort_it->LIST_IT_data_next))
			{
				size_1 = LIST_IT_data_size(sort_it);
				size_2 = LIST_IT_data_size(next_node);
				for(cmp_i = 0; cmp_i >= 0; cmp_i++)
				{
					if(cmp_i >= size_2) break;
					if(cmp_i >= size_1)
					{
						if((temp_node = Pointer:MEM_EX::get_val(sort_it->LIST_IT_data_previous)))
						{
							MEM::set_val(temp_node, LIST_IT_data_next, _:next_node);
							MEM::set_val(next_node, LIST_IT_data_previous, _:temp_node);
						}
						else MEM::set_val((Pointer:list[LIST_base_begin] = next_node), LIST_IT_data_previous, LIST_NULL_);
						if((temp_node = Pointer:MEM_EX::get_val(next_node->LIST_IT_data_next)))
						{
							MEM::set_val(temp_node, LIST_IT_data_previous, _:sort_it);
							MEM::set_val(sort_it, LIST_IT_data_next, _:temp_node);
						}
						else MEM::set_val((Pointer:list[LIST_base_end] = sort_it), LIST_IT_data_next, LIST_NULL_);
						MEM::set_val(sort_it, LIST_IT_data_previous, _:next_node);
						MEM::set_val(next_node, LIST_IT_data_next, _:sort_it);
						sort_it = next_node;
						allow_repeat = true;
						break;
					}
					if((data_1 = MEM_EX::get_val(sort_it->LIST_IT_data_data_offset+cmp_i)) == (data_2 = MEM_EX::get_val(next_node->LIST_IT_data_data_offset+cmp_i))) continue;
					if(data_1 > data_2) break;
					if((temp_node = Pointer:MEM_EX::get_val(sort_it->LIST_IT_data_previous)))
					{
						MEM::set_val(temp_node, LIST_IT_data_next, _:next_node);
						MEM::set_val(next_node, LIST_IT_data_previous, _:temp_node);
					}
					else MEM::set_val((Pointer:list[LIST_base_begin] = next_node), LIST_IT_data_previous, LIST_NULL_);
					if((temp_node = Pointer:MEM_EX::get_val(next_node->LIST_IT_data_next)))
					{
						MEM::set_val(temp_node, LIST_IT_data_previous, _:sort_it);
						MEM::set_val(sort_it, LIST_IT_data_next, _:temp_node);
					}
					else MEM::set_val((Pointer:list[LIST_base_end] = sort_it), LIST_IT_data_next, LIST_NULL_);
					MEM::set_val(sort_it, LIST_IT_data_previous, _:next_node);
					MEM::set_val(next_node, LIST_IT_data_next, _:sort_it);
					sort_it = next_node;
					allow_repeat = true;
					break;
				}
			}
		}
	}
	else
	{
		while(allow_repeat)
		{
			allow_repeat = false;
			for(sort_it = Pointer:list[LIST_base_begin]; (next_node = Pointer:MEM_EX::get_val(sort_it->LIST_IT_data_next)); sort_it = Pointer:MEM_EX::get_val(sort_it->LIST_IT_data_next))
			{
				size_1 = LIST_IT_data_size(sort_it);
				size_2 = LIST_IT_data_size(next_node);
				for(cmp_i = 0; cmp_i >= 0; cmp_i++)
				{
					if(cmp_i >= size_1) break;
					if(cmp_i >= size_2)
					{
						if((temp_node = Pointer:MEM_EX::get_val(sort_it->LIST_IT_data_previous)))
						{
							MEM::set_val(temp_node, LIST_IT_data_next, _:next_node);
							MEM::set_val(next_node, LIST_IT_data_previous, _:temp_node);
						}
						else MEM::set_val((Pointer:list[LIST_base_begin] = next_node), LIST_IT_data_previous, LIST_NULL_);
						if((temp_node = Pointer:MEM_EX::get_val(next_node->LIST_IT_data_next)))
						{
							MEM::set_val(temp_node, LIST_IT_data_previous, _:sort_it);
							MEM::set_val(sort_it, LIST_IT_data_next, _:temp_node);
						}
						else MEM::set_val((Pointer:list[LIST_base_end] = sort_it), LIST_IT_data_next, LIST_NULL_);
						MEM::set_val(sort_it, LIST_IT_data_previous, _:next_node);
						MEM::set_val(next_node, LIST_IT_data_next, _:sort_it);
						sort_it = next_node;
						allow_repeat = true;
						break;
					}
					if((data_1 = MEM_EX::get_val(sort_it->LIST_IT_data_data_offset+cmp_i)) == (data_2 = MEM_EX::get_val(next_node->LIST_IT_data_data_offset+cmp_i))) continue;
					if(data_1 < data_2) break;
					if((temp_node = Pointer:MEM_EX::get_val(sort_it->LIST_IT_data_previous)))
					{
						MEM::set_val(temp_node, LIST_IT_data_next, _:next_node);
						MEM::set_val(next_node, LIST_IT_data_previous, _:temp_node);
					}
					else MEM::set_val((Pointer:list[LIST_base_begin] = next_node), LIST_IT_data_previous, LIST_NULL_);
					if((temp_node = Pointer:MEM_EX::get_val(next_node->LIST_IT_data_next)))
					{
						MEM::set_val(temp_node, LIST_IT_data_previous, _:sort_it);
						MEM::set_val(sort_it, LIST_IT_data_next, _:temp_node);
					}
					else MEM::set_val((Pointer:list[LIST_base_end] = sort_it), LIST_IT_data_next, LIST_NULL_);
					MEM::set_val(sort_it, LIST_IT_data_previous, _:next_node);
					MEM::set_val(next_node, LIST_IT_data_next, _:sort_it);
					sort_it = next_node;
					allow_repeat = true;
					break;
				}
			}
		}
	}
}
stock LIST_count_nodes(List:list[])
{
	new count = 0;
	for(new Pointer:list_it = Pointer:list[LIST_base_begin]; _:list_it != LIST_NULL_; list_it = Pointer:MEM_EX::get_val(list_it->LIST_IT_data_next)) count++;
	return count;
}
stock LIST_get_data_cell_size(List:list[])
{
	new count = 0;
	for(new Pointer:list_it = Pointer:list[LIST_base_begin]; _:list_it != LIST_NULL_; list_it = Pointer:MEM_EX::get_val(list_it->LIST_IT_data_next)) count += LIST_IT_data_size(list_it);
	return count;
}
stock LIST_get_all_cell_size(List:list[])
{
	new count = 0;
	for(new Pointer:list_it = Pointer:list[LIST_base_begin]; _:list_it != LIST_NULL_; list_it = Pointer:MEM_EX::get_val(list_it->LIST_IT_data_next)) count += (LIST_IT_data_size(list_it)+3);
	return count;
}
stock LIST_clear(List:list[])
{
	if(list[LIST_base_begin] == LIST_NULL_) return;
	new Pointer:last_node = Pointer:list[LIST_base_end], Pointer:free_node;
	while((free_node = last_node))
	{
		last_node = Pointer:MEM_EX::get_val(last_node->LIST_IT_data_previous);
		MEM::free(free_node);
	}
	list[LIST_base_begin] = LIST_NULL_;
	list[LIST_base_end] = LIST_NULL_;
}
stock bool:LIST_copy(List:dest_list[], List:src_list[])
{
	new Pointer:next_LIST_ptr, arr_size;
	LIST_clear(dest_list);
	for(new Pointer:list_it = Pointer:src_list[LIST_base_begin]; _:list_it != LIST_NULL_; list_it = Pointer:MEM_EX::get_val(Pointer:list_it->LIST_IT_data_next))
	{
		if((next_LIST_ptr = MEM::calloc((arr_size = MEM_EX::get_val(Pointer:list_it->LIST_IT_data_data_size))+LIST_IT_data_data_offset)) == Pointer:LIST_NULL_)
		{
			LIST_clear(dest_list);
			return false;
		}
		MEM::copy(next_LIST_ptr, list_it, arr_size+1, LIST_IT_data_data_size, LIST_IT_data_data_size);
		if(dest_list[LIST_base_end])
		{
			MEM::set_val(Pointer:dest_list[LIST_base_end], LIST_IT_data_next, _:next_LIST_ptr);
			MEM::set_val(next_LIST_ptr, LIST_IT_data_previous, dest_list[LIST_base_end]);
		}
		else if(dest_list[LIST_base_begin] == LIST_NULL_) dest_list[LIST_base_begin] = _:next_LIST_ptr;
		dest_list[LIST_base_end] = _:next_LIST_ptr;
	}
	return true;
}
stock bool:LIST_save(List:list[], const file_name[], bool:clear = false)
{
	new File:list_file = fopen(file_name, io_write);
	if(list_file)
	{
		new arr_size, i, buffer
#if !defined SECURE_MEMORY_PLUGIN
			, Pointer:data_ptr
#endif
			;
		for(i = 0; i < sizeof LIST_file_header; i++) fputchar(list_file, LIST_file_header[i], false);
		for(new Pointer:list_it = Pointer:list[LIST_base_begin]; _:list_it != LIST_NULL_; list_it = Pointer:MEM_EX::get_val(Pointer:list_it->LIST_IT_data_next))
		{
			fputchar(list_file, 1, false);
			fputchar(list_file, (arr_size = MEM_EX::get_val(Pointer:list_it->LIST_IT_data_data_size))&0xFF, false);
			fputchar(list_file, (arr_size>>>8)&0xFF, false);
			fputchar(list_file, (arr_size>>>16)&0xFF, false);
			fputchar(list_file, (arr_size>>>24)&0xFF, false);
#if !defined SECURE_MEMORY_PLUGIN
			data_ptr = MEM_EX::get_ptr(list_it->LIST_IT_data_data_offset);
#endif
			for(i = 0; i < arr_size; i++)
			{
#if defined SECURE_MEMORY_PLUGIN
				fputchar(list_file, (buffer = LIST_IT_data_val(list_it, i))&0xFF, false);
#else
				fputchar(list_file, (buffer = MEM_EX::get_val(data_ptr->i))&0xFF, false);
#endif
				fputchar(list_file, (buffer>>>8)&0xFF, false);
				fputchar(list_file, (buffer>>>16)&0xFF, false);
				fputchar(list_file, (buffer>>>24)&0xFF, false);
			}
		}
		fclose(list_file);
		if(clear) LIST_clear(list);
		return true;
	}
	printf(" [LIST] LIST_save(): Failed to open or create file \"%s\".", file_name);
	return false;
}
stock bool:LIST_load(List:list[], const file_name[], bool:rewrite = true)
{
	new File:list_file = fopen(file_name, io_read);
	if(list_file)
	{
		new Pointer:next_LIST_ptr, arr_size, i, j, k, buffer, buffer_temp
#if !defined SECURE_MEMORY_PLUGIN
			, Pointer:data_ptr
#endif
			;
		for(i = 0; i < sizeof LIST_file_header; i++)
		{
			if(LIST_file_header[i] == fgetchar(list_file, 0, false)) continue;
			fclose(list_file);
			printf(" [LIST] LIST_load(): Invalid file header. \"%s\"", file_name);
			if(rewrite) LIST_clear(list);
			return false;
		}
		if(rewrite) LIST_clear(list);
		for(i = 1; ; i++)
		{
			if(fgetchar(list_file, 0, false) != 1) break;
			for(arr_size = (j = 0); j < 4; j++)
			{
				if((buffer_temp = fgetchar(list_file, 0, false)) == EOF)
				{
					fclose(list_file);
					printf(" [LIST] LIST_load(): Unexpected end of file. \"%s\"", file_name);
					if(rewrite) LIST_clear(list);
					return false;
				}
				arr_size |= (buffer_temp&0xFF)<<(j*8);
			}
			if(arr_size < 1)
			{
				fclose(list_file);
				printf(" [LIST] LIST_load(): Invalid array size (%d) at %d. node. \"%s\"", arr_size, i, file_name);
				if(rewrite) LIST_clear(list);
				return false;
			}
			if((next_LIST_ptr = MEM::calloc(arr_size+LIST_IT_data_data_offset)) == Pointer:LIST_NULL_)
			{
				fclose(list_file);
				if(rewrite) LIST_clear(list);
				return false;
			}
			if(list[LIST_base_end])
			{
				MEM::set_val(Pointer:list[LIST_base_end], LIST_IT_data_next, _:next_LIST_ptr);
				MEM::set_val(next_LIST_ptr, LIST_IT_data_previous, list[LIST_base_end]);
			}
			else if(list[LIST_base_begin] == LIST_NULL_) list[LIST_base_begin] = _:next_LIST_ptr;
			list[LIST_base_end] = _:next_LIST_ptr;
			MEM::set_val(next_LIST_ptr, LIST_IT_data_data_size, arr_size);
#if !defined SECURE_MEMORY_PLUGIN
			data_ptr = MEM_EX::get_ptr(next_LIST_ptr->LIST_IT_data_data_offset);
#endif
			for(j = 0; j < arr_size; j++)
			{
				for(buffer = (k = 0); k < 4; k++)
				{
					if((buffer_temp = fgetchar(list_file, 0, false)) == EOF)
					{
						fclose(list_file);
						printf(" [LIST] LIST_load(): Unexpected end of file. \"%s\"", file_name);
						if(rewrite) LIST_clear(list);
						return false;
					}
					buffer |= (buffer_temp&0xFF)<<(k*8);
				}
#if defined SECURE_MEMORY_PLUGIN
			MEM::set_val(next_LIST_ptr, LIST_IT_data_data_offset+j, buffer);
#else
			MEM::set_val(data_ptr, j, buffer);
#endif
			}
		}
		fclose(list_file);
		return true;
	}
	printf(" [LIST] LIST_load(): Failed to open file \"%s\".", file_name);
	return false;
}
#define LIST::							LIST_
#define LIST_IT::						LIST_IT_