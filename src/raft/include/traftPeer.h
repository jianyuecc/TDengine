/*
 * Copyright (c) 2019 TAOS Data, Inc. <jhtao@taosdata.com>
 *
 * This program is free software: you can use, redistribute, and/or modify
 * it under the terms of the GNU Affero General Public License, version 3
 * or later ("AGPL"), as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _TD_TRAFT_PEER_H_
#define _TD_TRAFT_PEER_H_

#ifdef __cplusplus
extern "C" {
#endif

#define RAFT_PEER_ID_FIELDS \
  raft_node_id_t nodeid;    \
  vid_t          vid;

typedef struct {
  RAFT_PEER_ID_FIELDS
} traft_peer_id;

typedef struct {
  RAFT_PEER_ID_FIELDS

  raft_index_t nextIdx;  // next log entry to send to that server
  raft_index_t matchIdx;  // index of highest log entry known to be replicated on server
} SRaftPeer;

#define RAFT_PEER_NODE_ID(peer) ((peer)->nodeid)
#define RAFT_PEER_VID(peer) ((peer)->vid)

#ifdef __cplusplus
}
#endif

#endif /*_TD_TRAFT_PEER_H_*/