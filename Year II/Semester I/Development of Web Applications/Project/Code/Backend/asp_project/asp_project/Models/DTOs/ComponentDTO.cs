﻿using asp_project.Models.Entities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;

namespace asp_project.Models.DTOs
{
    public class ComponentDTO
    {
        public int ComponentId { get; set; }
        public string ComponentName { get; set; }
        public string Seller { get; set; }
        public bool RecommendedForGaming { get; set; }
        public double Price { get; set; }

        public ComponentDTO(Component comp)
        {
            this.ComponentId = comp.ComponentId;
            this.ComponentName = comp.ComponentName;
            this.Seller = comp.Seller;
            this.RecommendedForGaming = comp.RecommendedForGaming;
            this.Price = comp.Price;
        }
    }
}
