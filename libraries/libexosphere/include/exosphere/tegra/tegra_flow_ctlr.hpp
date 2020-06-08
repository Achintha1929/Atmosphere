/*
 * Copyright (c) 2018-2020 Atmosphère-NX
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once
#include <vapours.hpp>


#define FLOW_CTLR_FLOW_DBG_QUAL        (0x050)
#define FLOW_CTLR_L2FLUSH_CONTROL      (0x094)
#define FLOW_CTLR_BPMP_CLUSTER_CONTROL (0x098)

#define FLOW_CTLR_CPU0_CSR             (0x008)
#define FLOW_CTLR_CPU1_CSR             (0x018)
#define FLOW_CTLR_CPU2_CSR             (0x020)
#define FLOW_CTLR_CPU3_CSR             (0x028)

#define FLOW_CTLR_HALT_CPU0_EVENTS     (0x000)
#define FLOW_CTLR_HALT_CPU1_EVENTS     (0x014)
#define FLOW_CTLR_HALT_CPU2_EVENTS     (0x01C)
#define FLOW_CTLR_HALT_CPU3_EVENTS     (0x024)
#define FLOW_CTLR_HALT_COP_EVENTS      (0x004)

#define FLOW_CTLR_CC4_CORE0_CTRL       (0x06C)
#define FLOW_CTLR_CC4_CORE1_CTRL       (0x070)
#define FLOW_CTLR_CC4_CORE2_CTRL       (0x074)
#define FLOW_CTLR_CC4_CORE3_CTRL       (0x078)

#define FLOW_REG_BITS_MASK(NAME)                                      REG_NAMED_BITS_MASK    (FLOW_CTLR, NAME)
#define FLOW_REG_BITS_VALUE(NAME, VALUE)                              REG_NAMED_BITS_VALUE   (FLOW_CTLR, NAME, VALUE)
#define FLOW_REG_BITS_ENUM(NAME, ENUM)                                REG_NAMED_BITS_ENUM    (FLOW_CTLR, NAME, ENUM)
#define FLOW_REG_BITS_ENUM_SEL(NAME, __COND__, TRUE_ENUM, FALSE_ENUM) REG_NAMED_BITS_ENUM_SEL(FLOW_CTLR, NAME, __COND__, TRUE_ENUM, FALSE_ENUM)

#define DEFINE_FLOW_REG(NAME, __OFFSET__, __WIDTH__)                                                                                                                  REG_DEFINE_NAMED_REG           (FLOW_CTLR, NAME, __OFFSET__, __WIDTH__)
#define DEFINE_FLOW_REG_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE)                                                                                                         REG_DEFINE_NAMED_BIT_ENUM      (FLOW_CTLR, NAME, __OFFSET__, ZERO, ONE)
#define DEFINE_FLOW_REG_TWO_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE)                                                                                         REG_DEFINE_NAMED_TWO_BIT_ENUM  (FLOW_CTLR, NAME, __OFFSET__, ZERO, ONE, TWO, THREE)
#define DEFINE_FLOW_REG_THREE_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)                                                               REG_DEFINE_NAMED_THREE_BIT_ENUM(FLOW_CTLR, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN)
#define DEFINE_FLOW_REG_FOUR_BIT_ENUM(NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN) REG_DEFINE_NAMED_FOUR_BIT_ENUM (FLOW_CTLR, NAME, __OFFSET__, ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, ELEVEN, TWELVE, THIRTEEN, FOURTEEN, FIFTEEN)

DEFINE_FLOW_REG_BIT_ENUM(CPUN_CSR_ENABLE, 0, DISABLE, ENABLE);
DEFINE_FLOW_REG(CPUN_CSR_WAIT_WFI_BITMAP, 8, 4);
DEFINE_FLOW_REG_TWO_BIT_ENUM(CPUN_CSR_ENABLE_EXT, 12, POWERGATE_CPU_ONLY, POWERGATE_BOTH_CPU_NONCPU, POWERGATE_CPU_TURNOFF_CPURAIL, PG_EMULATION);
DEFINE_FLOW_REG_BIT_ENUM(CPUN_CSR_EVENT_FLAG, 14, FALSE, TRUE);
DEFINE_FLOW_REG_BIT_ENUM(CPUN_CSR_INTR_FLAG, 15, FALSE, TRUE);

DEFINE_FLOW_REG_BIT_ENUM(HALT_CPUN_EVENTS_GIC_FIQN,  8, DISABLE, ENABLE);
DEFINE_FLOW_REG_BIT_ENUM(HALT_CPUN_EVENTS_GIC_IRQN,  9, DISABLE, ENABLE);
DEFINE_FLOW_REG_BIT_ENUM(HALT_CPUN_EVENTS_LIC_FIQN, 10, DISABLE, ENABLE);
DEFINE_FLOW_REG_BIT_ENUM(HALT_CPUN_EVENTS_LIC_IRQN, 11, DISABLE, ENABLE);

DEFINE_FLOW_REG_THREE_BIT_ENUM(HALT_CPUN_EVENTS_FLOW_MODE, 29, NONE, RUN_AND_INT, WAITEVENT, WAITEVENT_AND_INT, STOP_UNTIL_IRQ, STOP_UNTIL_EVENT_AND_IRQ, RESERVED6, RESERVED7);

DEFINE_FLOW_REG_BIT_ENUM(HALT_COP_EVENTS_JTAG, 28, ENABLED, DISABLED);
DEFINE_FLOW_REG_THREE_BIT_ENUM(HALT_COP_EVENTS_MODE, 29, FLOW_MODE_NONE, FLOW_MODE_RUN_AND_INT, FLOW_MODE_STOP, FLOW_MODE_STOP_AND_INT, FLOW_MODE_STOP_UNTIL_IRQ, FLOW_MODE_STOP_UNTIL_IRQ_AND_INT, FLOW_MODE_STOP_UNTIL_EVENT_AND_IRQ, RESERVED7);

DEFINE_FLOW_REG_BIT_ENUM(FLOW_DBG_QUAL_FIQ2CCPLEX_ENABLE, 28, DISABLE, ENABLE);

DEFINE_FLOW_REG_BIT_ENUM(BPMP_CLUSTER_CONTROL_ACTIVE_CLUSTER,        0, FAST, SLOW);
DEFINE_FLOW_REG_BIT_ENUM(BPMP_CLUSTER_CONTROL_CLUSTER_SWITCH_ENABLE, 1, DISABLE, ENABLE);
DEFINE_FLOW_REG_BIT_ENUM(BPMP_CLUSTER_CONTROL_ACTIVE_CLUSTER_LOCK,   2, DISABLE, ENABLE);
