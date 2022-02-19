import { TestBed } from '@angular/core/testing';

import { PcComponentsService } from './pc-components.service';

describe('PcComponentsService', () => {
  let service: PcComponentsService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(PcComponentsService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
