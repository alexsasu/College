import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { PcPartComponent } from './pc-part/pc-part.component';
import { PcComponentsComponent } from './pc-components/pc-components.component';

const routes: Routes = [
  {
    path: '',
    component: PcComponentsComponent
  },
  {
    path: 'pc-part/:id',
    component: PcPartComponent
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule]
})
export class PcComponentsRoutingModule { }
